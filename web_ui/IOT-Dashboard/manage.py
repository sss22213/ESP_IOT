#!/usr/bin/env python
"""Django's command-line utility for administrative tasks."""
import os
import sys
import readings.sys_init

'''
System core
'''
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
# token = '5180607144:AAEbnhu9rz_cow7XfhdZdm8242gy0WwJycA'

def main():
    os.environ.setdefault('DJANGO_SETTINGS_MODULE', 'iot.settings')
    try:
        from django.core.management import execute_from_command_line
    except ImportError as exc:
        raise ImportError(
            "Couldn't import Django. Are you sure it's installed and "
            "available on your PYTHONPATH environment variable? Did you "
            "forget to activate a virtual environment?"
        ) from exc
    execute_from_command_line(sys.argv)

if __name__ == '__main__':
    # system = readings.sys_init.sys_init()
    readings.sys_init.system = readings.sys_init.sys_init()
    readings.sys_init.system.connect()

    '''
    new_mqtt = mqtt._mqtt('broker.hivemq.com')
    new_mqtt.wait_connect_to_broker()
    # new_mqtt.subscribe('SYSTEM')
    new_mqtt.subscribe('SHT20_Temperature')
    new_mqtt.subscribe('SHT20_Humidity')

    timestamp_timer = Timer(0, event.timestamp_event, [new_mqtt])
    timestamp_timer.start()
    '''

    '''
    bot = telegram.Bot(token=token)
    telegram_plugin_obj = telegram_plugin._telegram_plugin()
    receive_buf = [None]
    bot_timer = Timer(0, event.telegram_event, [bot, receive_buf, telegram_plugin_obj])
    bot_timer.start()
    '''

    main()
