from django.shortcuts import render
from django.views import View
from django.http import JsonResponse
from django.views.decorators.cache import cache_page
from django.core.cache.backends.base import DEFAULT_TIMEOUT
from easy_pdf.views import PDFTemplateView
from django.conf import settings
import requests
import json
import sys
import time
import readings.sys_init
from io import BytesIO
from django.http import HttpResponse
from django.conf import settings
from selenium import webdriver
from webdriver_manager.chrome import ChromeDriverManager
from selenium.webdriver.chrome.options import Options
from reportlab.platypus import SimpleDocTemplate, Image
from django.contrib.sites.shortcuts import get_current_site
import os

sys.path.append('../system/scripts')
import event
import sensor


CACHE_TTL = getattr(settings, 'CACHE_TTL', DEFAULT_TIMEOUT)
# Create your views here.
class Home(View):
    template_name = 'home.html'

    def get(self, request, *args, **kwargs):
        data = []
        '''
        r = requests.get(
            'https://api.thingspeak.com/channels/306267/feeds.json?results=1'
            , params=request.GET)   
        if r.status_code == 200:
            data = r.json()
        temp = data['feeds'][0]['field1'] 
        mositure =  data['feeds'][0]['field2']
        at =  data['feeds'][0]['field3']
        '''
        temp = 25.4
        mositure = 26.0
        at = 871
        return render(request, self.template_name,
                    {'temp': temp, 'mositure': mositure, 'at':  at,
                     'activedashboard': 'active'})

class Temperature(View):
    template_name = 'temperature.html'

    def get(self, request, *args, **kwargs):
        return render(request, self.template_name,
                        {'activetemp': 'active'})

class Moisture(View):
    template_name = 'moisture.html'

    def get(self, request, *args, **kwargs):
        return render(request, self.template_name,
                        {'activemositure': 'active'})

class Pressure(View):
    template_name = 'at.html'

    def get(self, request, *args, **kwargs):
        return render(request, self.template_name,
                        {'activepressure': 'active'})   

class PDF(View):
    def get(self, request, *args, **kwargs):
        data = []
        r = requests.get('https://api.thingspeak.com/channels/306267/feeds.json?results=100', params=request.GET)
        if r.status_code == 200:
            data = r.json()
        template_name = 'pdf-temp.html'     
        if kwargs['page'] == 2:
            template_name = 'pdf-moisture.html'
        elif kwargs['page'] == 3:  
            template_name = 'pdf-at.html'  
        return render(request, template_name,
                        {'activemositure': 'active', 'data_json': data})  
                         

class GeneratePdf(View):
    def get(self, request, *args, **kwargs):
        response = HttpResponse(content_type='application/pdf')
        local =  os.environ.get('local', True)
        doc = SimpleDocTemplate(response,topMargin=2)
        chrome_options = Options()
        chrome_bin = os.environ.get('GOOGLE_CHROME_BIN', None)
        chrome_options.add_argument("--disable-gpu")
        chrome_options.add_argument("--no-sandbox")
        chrome_options.add_argument("--headless") 
        chrome_options.binary_location = chrome_bin
        # For local environment
        if local:
            driver = webdriver.Chrome(ChromeDriverManager().install(),
                                chrome_options=chrome_options)
        else:                        
            chrome_exec_shim = os.environ.get("$GOOGLE_CHROME_SHIM", "chromedriver")
            driver = webdriver.Chrome(executable_path=chrome_exec_shim,
                                chrome_options=chrome_options)
        domain = 'http://{}'.format(get_current_site(request))
        url = "{}/pdf/{}".format(domain, str(kwargs['page']))                                                                   
        driver.get(url)
        total_width = driver.execute_script("return document.body.scrollWidth")
        total_height = driver.execute_script("return document.body.scrollHeight")
        driver.set_window_size(total_width, total_height)      
        screenshot = driver.get_screenshot_as_png()
        i = Image(BytesIO(screenshot))
        i.drawHeight =  700
        i.drawWidth = 600
        elements = []
        elements.append(i)
        doc.build(elements)
        return response

# @cache_page(CACHE_TTL)get_temperature_time
def get_readings(request):
    data = []
    r = requests.get('https://api.thingspeak.com/channels/306267/feeds.json?results=100', params=request.GET)
    if r.status_code == 200:
        data = r.json() 
    return JsonResponse(list(data['feeds']), safe=False)

# Get sensor information
def get_temperature(request):
    val = event.sensor_class.get_sensor_value("SHT20_Temperature")
    return HttpResponse(round(val,2))

def get_humidity(request):
    val = event.sensor_class.get_sensor_value("SHT20_Humidity")
    return HttpResponse(round(val,2))

def get_pm_1_0(request):
    val = event.sensor_class.get_sensor_value("PMS7003T_PM1_0")
    return HttpResponse(round(val,1))

def get_pm_2_5(request):
    val = event.sensor_class.get_sensor_value("PMS7003T_PM2_5")
    return HttpResponse(round(val,1))

def get_pm10(request):
    val = event.sensor_class.get_sensor_value("PMS7003T_PM10")
    return HttpResponse(round(val,1))

def get_sensor_update_time(request):
    sensor_name = request.POST.get('sensor_name')
    t1 = int(time.time())
    t2 = event.sensor_class.get_sensor_time(sensor_name)
    return HttpResponse(t1-t2)
'''
def get_humidity_time(request):
    t1 = int(time.time())
    t2 = event.sensor_class.get_sensor_time("SHT20_Humidity")
    return HttpResponse(t1-t2)

def get_temperature_time(request):
    t1 = int(time.time())
    t2 = event.sensor_class.get_sensor_time("SHT20_Temperature")
    return HttpResponse(t1-t2)

def get_pm_1_0_time(request):
    t1 = int(time.time())
    t2 = event.sensor_class.get_sensor_time("PMS7003T_PM1_0")
    return HttpResponse(round(val,1))

def get_pm_2_5_time(request):
    t1 = int(time.time())
    t2 = event.sensor_class.get_sensor_time("PMS7003T_PM2_5")
    return HttpResponse(round(val,1))

def get_pm10_time(request):
    t1 = int(time.time())
    t2 = event.sensor_class.get_sensor_time("PMS7003T_PM10")
    return HttpResponse(round(val,1))
'''
def get_mqtt_status(request):
    status = 0
    if readings.sys_init.system.get_sys_status() == True:
        status = 1

    return HttpResponse(status)

def mqtt_get_uri(request):
    #get_mqtt_uri
    return HttpResponse(str(readings.sys_init.system.get_mqtt_uri()))

# Summary page
def summary(request):
    return render(request, 'summary.html')

def get_sys_version(request):
    return HttpResponse(readings.sys_init.SYSTEM_VERSION)
    
def get_sensor_infomation(request):
    sensor_name = request.POST.get('sensor_name')
    pid, vid = event.sensor_class.get_sensor_pid_vid(sensor_name)
    data = {"VID": pid, 
            "PID": vid, 
            "UUID": event.sensor_class.get_sensor_uuid(sensor_name)
            }
    return HttpResponse(json.dumps(data), content_type='application/json')