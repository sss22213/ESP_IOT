import sys
sys.path.append('../../system/scripts')
import mqtt
import time
import message
import event
from threading import Timer
import telegram
import telegram_plugin
from telegram.ext import Updater
from telegram.ext import CommandHandler, CallbackQueryHandler
from telegram.ext import MessageHandler, Filters
from telegram import InlineKeyboardMarkup, InlineKeyboardButton

SYSTEM_VERSION = '1.0d'

class sys_init:
    def __init__(self, mqtt_uri='broker.hivemq.com'):
        self.mqtt_uri = mqtt_uri
        self.new_mqtt = mqtt._mqtt(mqtt_uri)

    def connect(self):
        self.new_mqtt.wait_connect_to_broker()
        # new_mqtt.subscribe('SYSTEM')

        self.sys_status = 0

        self.timestamp_timer = Timer(0, event.timestamp_event, [self.new_mqtt])
        self.timestamp_timer.start()

    def get_sys_status(self):
        # MQTT status
        if self.new_mqtt.get_mqtt_connect_status() == True:
            self.sys_status = self.sys_status | (1 << 0)
        else:
            self.sys_status = self.sys_status & ~(1 << 0)

        return self.sys_status

    def get_mqtt_uri(self):
        return self.mqtt_uri
        
system = None
# system = sys_init()