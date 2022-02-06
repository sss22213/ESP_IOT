import message

SENSOR_NAME_LIST = ['SHT20_Temperature', 'SHT20_Humidity']

class _sensor:
    def __init__(self):
        self._sensor_message_array = []
        for sensor_name in SENSOR_NAME_LIST:
            new_sensor = message._message()
            new_sensor.topic_name = sensor_name
            self._sensor_message_array.append(new_sensor)
        pass

    def set_sensor_time(self, NAME, TIME):
        for _sensor_message in self._sensor_message_array:
            if _sensor_message.topic_name == NAME:
                _sensor_message.timestamp = TIME
        pass

    def set_sensor_pid_vid(self, NAME, PID, VID):
        for _sensor_message in self._sensor_message_array:
            if _sensor_message.topic_name == NAME:
                _sensor_message.pid = int(PID)
                _sensor_message.vid = int(VID)
        pass

    def set_sensor_uuid(self, NAME, UUID):
        for _sensor_message in self._sensor_message_array:
            if _sensor_message.topic_name == NAME:
                _sensor_message.uuid = UUID
        pass

    def get_sensor_uuid(self, NAME):
        for _sensor_message in self._sensor_message_array:
            if _sensor_message.topic_name == NAME:
                return _sensor_message.uuid
        pass

    def get_sensor_pid_vid(self, NAME):
        for _sensor_message in self._sensor_message_array:
            if _sensor_message.topic_name == NAME:
                return _sensor_message.pid,_sensor_message.vid
        pass

    def get_sensor_info(self, NAME):
        return get_sensor_pid_vid(NAME), get_sensor_uuid(NAME)

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
        

        
    
