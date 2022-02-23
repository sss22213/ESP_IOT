import message
import mqtt
import json
import time
import sensor
import telegram
import telegram_plugin
from threading import Timer

BOT_POLLING_TIMER = 0.5
TIMESTAMP_TIMER = 1.0

sensor_class = sensor._sensor()

def telegram_event(bot, receive_buf, telegram_plugin_obj):
    new_message_flag = False
    if receive_buf[0] == None:
        if bot.getUpdates()[-1].message.text == None:
            return
        receive_buf[0] = bot.getUpdates()[-1].message.text
        new_message_flag = True
        
    elif receive_buf[0] != (bot.getUpdates()[-1].message.text):
        receive_buf[0] = bot.getUpdates()[-1].message.text
        new_message_flag = True

    if new_message_flag == True:
        cut_group = telegram_plugin_obj.cut(receive_buf[0])
        telegram_plugin_obj.word_to_action(cut_group)

    bot_timer = Timer(BOT_POLLING_TIMER, telegram_event, [bot, receive_buf, telegram_plugin_obj])
    bot_timer.start()
    pass

# MQTT message callback
def on_message(client, userdata, msg):
    msg_json = json.loads(msg.payload.decode('utf-8'))

    # Config information to sensor
    sensor_class.set_sensor_value(msg_json['NAME'], msg_json['VALUE'])
    sensor_class.set_sensor_time(msg_json['NAME'], msg_json['TIMESTAMP'])
    sensor_class.set_sensor_pid_vid(msg_json['NAME'], msg_json['PID'], msg_json['VID'])
    sensor_class.set_sensor_uuid(msg_json['NAME'], msg_json['UUID'])

    pass

def event_start():
    pass

# Publish timestamp
def timestamp_event(mqtt_object):
    mqtt_object.publish(message._MESSAGE_TYPE_TIMESTAMP_EVENT, 4, int(time.time()))
    #mqtt_object.publish(message._MESSAGE_TYPE_SYSTEM_EVENT, 4, 1)
    timestamp_timer = Timer(TIMESTAMP_TIMER, timestamp_event, [mqtt_object])
    timestamp_timer.start()
    pass