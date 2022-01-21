import mqtt
import time
import message
import event
from threading import Timer

if __name__ == '__main__':
    new_mqtt = mqtt._mqtt('broker.hivemq.com')
    new_mqtt.wait_connect_to_broker()
    new_mqtt.subscribe('SYSTEM')

    timestamp_timer = Timer(1.0, event.timestamp_event, [new_mqtt])
    timestamp_timer.start()
    
    while True:
        time.sleep(1)
        '''
        new_mqtt.publish(message._MESSAGE_TYPE_SYSTEM_EVENT, 1, 1)
        '''
        pass
