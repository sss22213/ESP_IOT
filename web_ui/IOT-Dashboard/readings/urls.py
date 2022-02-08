from django.urls import path
from django.views.decorators.cache import cache_page
from . import views

urlpatterns = [
    path('home',  (views.Home.as_view()), name='dashboard'),
    path('temp', views.Temperature.as_view(), name='temp'),
    path('mositure', views.Moisture.as_view(), name='moisture'),
    path('pressure', views.Pressure.as_view(), name='pressure'),
    path('readings', views.get_readings, name='readings'),
    path('pdf/<int:page>', views.PDF.as_view(), name='pdf'),
    path('generate-pdf/<int:page>', views.GeneratePdf.as_view(),
         name='generate-pdf'),
    path('summary', views.summary, name='summary'),
    path('get_temperature', views.get_temperature),   
    path('get_humidity', views.get_humidity),
    path('get_humidity_time', views.get_humidity_time),
    path('get_temperature_time', views.get_temperature_time),
    path('get_mqtt_status', views.get_mqtt_status),
    path('mqtt_get_uri', views.mqtt_get_uri),
    path('get_sys_version', views.get_sys_version),
    path('get_sensor_infomation', views.get_sensor_infomation),
    path('get_sensor_update_time', views.get_sensor_update_time),
]