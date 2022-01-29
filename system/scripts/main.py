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
token = '5180607144:AAEbnhu9rz_cow7XfhdZdm8242gy0WwJycA'

if __name__ == '__main__':
    new_mqtt = mqtt._mqtt('broker.hivemq.com')
    new_mqtt.wait_connect_to_broker()
    new_mqtt.subscribe('SYSTEM')

    timestamp_timer = Timer(0, event.timestamp_event, [new_mqtt])
    timestamp_timer.start()

    bot = telegram.Bot(token=token)
    telegram_plugin_obj = telegram_plugin._telegram_plugin()
    receive_buf = [None]
    bot_timer = Timer(0, event.telegram_event, [bot, receive_buf, telegram_plugin_obj])
    bot_timer.start()

    # new_mqtt.publish(message._MESSAGE_TYPE_SYSTEM_EVENT, 4, 1)
    
    while True:
        time.sleep(1)
        '''
        new_mqtt.publish(message._MESSAGE_TYPE_SYSTEM_EVENT, 1, 1)
        '''
        pass
