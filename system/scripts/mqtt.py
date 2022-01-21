import paho.mqtt.client as mqtt
import time
import message
import event
import json

class _mqtt_connect_infomation:
    URI = ""
    port = 0
    username = None
    password = None

'''
{"NAME":<name>,"TYPE":<type>,"VALUE":<value>,"ARG":<arg>,"TIMESTAMP":<timestamp>,"PID":<pid>,"VID":<vid>,"UUID":<UUID>}
'''

class _mqtt:
    def __init__(self, URI, port=1883, username=None, password=None):
        self.mqtt_connect_infomation = _mqtt_connect_infomation()
        self.mqtt_connect_infomation.URI = URI
        self.mqtt_connect_infomation.username = username
        self.mqtt_connect_infomation.password = password
        self.mqtt_connect_infomation.port = port

        self.connect_flags = False

        self.client = mqtt.Client()
        self.client.on_connect = self.on_connect
        self.client.on_message = event.on_message

        if self.mqtt_connect_infomation.username != None and self.mqtt_connect_infomation.password != None:
            self.client.username_pw_set(mqtt_connect_infomation.username, mqtt_connect_infomation.password)
        
        self.connect()

    def on_connect(self, client, userdata, flags, rc):
        print("Already connect to broker.")
        self.connect_flags = True
        pass

    def wait_connect_to_broker(self):
        while self.connect_flags != True:
            pass

    def connect(self):
        self.client.connect(self.mqtt_connect_infomation.URI, self.mqtt_connect_infomation.port, 60)
        self.client.loop_start()
       
    def disconnect(self):
        self.client.loop_stop()
        self.connect_flags = False

    def publish(self, message_type, value, arg):
        new_message = message._message()
        new_message.timestamp = int(time.time())
        new_message.message_type = message_type
        new_message.value = value
        new_message.arg = arg

        self.new_message_json = {"NAME":new_message.topic_name,"TYPE":new_message.message_type,"VALUE":new_message.value,\
                                    "ARG":new_message.arg,"TIMESTAMP":new_message.timestamp,\
                                    "PID":new_message.pid,"VID":new_message.vid,"UUID":new_message.uuid}

        self.client.publish(new_message.topic_name, json.dumps(self.new_message_json).replace(' ',''))
        pass

    def subscribe(self, topic_name):
        self.client.subscribe(topic_name)
        
if __name__ == '__main__':
    new_mqtt = _mqtt('127.0.0.1')
    new_mqtt.wait_connect_to_broker()
    new_mqtt.subscribe('SYSTEM')
    while True:
        time.sleep(1)
        new_mqtt.publish(message._MESSAGE_TYPE_SYSTEM_EVENT, 1, 1)
        pass