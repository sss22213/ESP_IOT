import message
import mqtt
import telegram
import telegram_plugin
from threading import Timer

BOT_POLLING_TIMER = 0.5
TIMESTAMP_TIMER = 1.0

def telegram_event(bot, receive_buf, telegram_plugin_obj):
    # New message come in.
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

    #receive_buf[0] = bot.getUpdates()[-1].message.text
    #print(bot.getUpdates()[-1].message.text)
    bot_timer = Timer(BOT_POLLING_TIMER, telegram_event, [bot, receive_buf, telegram_plugin_obj])
    bot_timer.start()
    pass

def on_message(client, userdata, msg):
    print(msg.payload.decode('utf-8'))
    pass

def event_start():
    pass

def timestamp_event(mqtt_object):
    # mqtt_object.publish(message._MESSAGE_TYPE_TIMESTAMP_EVENT, 1.0, 1.0)
    mqtt_object.publish(message._MESSAGE_TYPE_SYSTEM_EVENT, 4, 1)
    timestamp_timer = Timer(TIMESTAMP_TIMER, timestamp_event, [mqtt_object])
    timestamp_timer.start()
    pass