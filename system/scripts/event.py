import message
import mqtt
from threading import Timer

def on_message(client, userdata, msg):
    print(msg.payload.decode('utf-8'))
    pass

def event_start():
    pass

def timestamp_event(mqtt_object):
    mqtt_object.publish(message._MESSAGE_TYPE_TIMESTAMP_EVENT, 1.0, 1.0)
    timestamp_timer = Timer(1.0, timestamp_event, [mqtt_object])
    timestamp_timer.start()
    pass