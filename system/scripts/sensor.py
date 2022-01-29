import message

class _sensor:
    def __init__(self):
        self._sensor_temperature_message = message._message()
        self._sensor_humidity_message = message._message()
        self._sensor_temperature_message.topic_name = 'SHT20_Temperature'
        self._sensor_humidity_message.topic_name = 'SHT20_Humidity'
        self._sensor_message_array = [self._sensor_temperature_message, self._sensor_humidity_message]

    def set_sensor_time(self, NAME, TIME):
        for _sensor_message in self._sensor_message_array:
            if _sensor_message.topic_name == NAME:
                _sensor_message.timestamp = TIME
        pass

    def get_sensor_time(self, NAME):
        for _sensor_message in self._sensor_message_array:
            if _sensor_message.topic_name == NAME:
                return _sensor_message.timestamp
        pass

    def set_sensor_value(self, NAME, VALUE):
        for _sensor_message in self._sensor_message_array:
            if _sensor_message.topic_name == NAME:
                _sensor_message.value = VALUE
        pass

    def get_sensor_value(self, NAME):
        for _sensor_message in self._sensor_message_array:
            if _sensor_message.topic_name == NAME:
                return _sensor_message.value
        pass
        

        
    
