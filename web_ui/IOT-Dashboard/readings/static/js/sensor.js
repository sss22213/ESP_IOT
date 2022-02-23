$(function() {
    function connected_quality(time) {
        if (time < 3) {
            return "Excellence";
        } else if (time < 4) {
            return "Good";
        } else {
            return "Disconnect";
        }
    }

    function read_temperature() {
        $.ajax({
            url: '/get_temperature',
            type: 'get',
            success: function(data) {
                $("#temperature").html(data);
            },
        }); 
        
    };
    function read_humidity() {
        $.ajax({
            url: '/get_humidity',
            type: 'get',
            success: function(data) {
                $("#humidity").html(data);
            },
        }); 
        
    };
    function read_pm_1_0() {
        $.ajax({
            url: '/get_pm_1_0',
            type: 'get',
            success: function(data) {
                $("#pm_1_0").html(data);
            },
        }); 
        
    };
    function read_pm_2_5() {
        $.ajax({
            url: '/get_pm_2_5',
            type: 'get',
            success: function(data) {
                $("#pm_2_5").html(data);
            },
        }); 
        
    };
    function read_pm10() {
        $.ajax({
            url: '/get_pm10',
            type: 'get',
            success: function(data) {
                $("#pm10").html(data);
            },
        }); 
        
    };
    function read_pm_1_0_time() {
        $.ajax({
            url: '/get_sensor_update_time',
            data : {sensor_name: "PMS5003T_PM1_0", csrfmiddlewaretoken: document.getElementsByName('csrfmiddlewaretoken')[0].value},
            type: 'post',
            //type: 'get',
            success: function(data) {
                $("#pm_1_0_update_time").html("Updated " + data + " seconds ago");
                $("#pm_1_0_connection_quality").html("Connect quality : " + connected_quality((parseInt(data, 10))));
            },
        }); 
    };
    function read_pm_2_5_time() {
        $.ajax({
            url: '/get_sensor_update_time',
            data : {sensor_name: "PMS5003T_PM2_5", csrfmiddlewaretoken: document.getElementsByName('csrfmiddlewaretoken')[0].value},
            type: 'post',
            //type: 'get',
            success: function(data) {
                $("#pm_2_5_update_time").html("Updated " + data + " seconds ago");
                $("#pm_2_5_connection_quality").html("Connect quality : " + connected_quality((parseInt(data, 10))));
            },
        }); 
    };
    function read_pm10_time() {
        $.ajax({
            url: '/get_sensor_update_time',
            data : {sensor_name: "PMS5003T_PM10", csrfmiddlewaretoken: document.getElementsByName('csrfmiddlewaretoken')[0].value},
            type: 'post',
            //type: 'get',
            success: function(data) {
                $("#pm10_update_time").html("Updated " + data + " seconds ago");
                $("#pm10_connection_quality").html("Connect quality : " + connected_quality((parseInt(data, 10))));
            },
        }); 
    };
    function read_humidity_time() {
        $.ajax({
            url: '/get_sensor_update_time',
            data : {sensor_name: "SHT20_Humidity", csrfmiddlewaretoken: document.getElementsByName('csrfmiddlewaretoken')[0].value},
            type: 'post',
            //type: 'get',
            success: function(data) {
                $("#humidity_update_time").html("Updated " + data + " seconds ago");
                $("#humidity_connection_quality").html("Connect quality : " + connected_quality((parseInt(data, 10))));
            },
        }); 
    };
    function read_temperature_time() {
        $.ajax({
            url: '/get_sensor_update_time',
            data : {sensor_name: "SHT20_Temperature", csrfmiddlewaretoken: document.getElementsByName('csrfmiddlewaretoken')[0].value},
            type: 'post',
            success: function(data) {
                $("#temperature_update_time").html("Updated " + data + " seconds ago");
                $("#temperature_connection_quality").html("Connect quality : " + connected_quality((parseInt(data, 10))));
            },
        }); 
        
    };

    function mqtt_server_status() {
        $.ajax({
            url: '/get_mqtt_status',
            type: 'get',
            success: function(data) {
                if (data == 1) {
                    $("#mqtt_server_status").html("Connected to MQTT broker");
                } else {
                    $("#mqtt_server_status").html("Disconnect");
                }
            },
            error: function() {
                $("#mqtt_server_status").html("Disconnect");
            },
        }); 
    };
    function mqtt_get_uri() {
        $.ajax({
            url: '/mqtt_get_uri',
            type: 'get',
            success: function(data) {
                $("#MQTT_broker_uri").html("MQTT broker URI : " + data);
            },
            error: function() {
                $("#MQTT_broker_uri").html("Cannot get broker URI.");
            },
        }); 
    }
    function get_sys_version() {
        $.ajax({
            url: '/get_sys_version',
            type: 'get',
            success: function(data) {
                $("#system_version").html("System version : " + data);
            },
            error: function() {
                $("#system_version").html("Cannot get system version");
            },
        }); 
    }
    function get_temperature_infomation() {
        $.ajax({
            url: '/get_sensor_infomation',
            data : {sensor_name: "SHT20_Temperature", csrfmiddlewaretoken: document.getElementsByName('csrfmiddlewaretoken')[0].value},
            type: 'post',
            success: function(data) {
                //console.log(data["PID"]);
                $("#temperature_pid").html("PID : " + data["PID"]);
                $("#temperature_vid").html("VID : " + data["VID"]);
                $("#temperature_uuid").html("UUID : " + data["UUID"]);
            },
        }); 
    };
    function get_humidity_infomation() {
        $.ajax({
            url: '/get_sensor_infomation',
            data : {sensor_name: "SHT20_Humidity", csrfmiddlewaretoken: document.getElementsByName('csrfmiddlewaretoken')[0].value},
            type: 'post',
            success: function(data) {
                //console.log(data["PID"]);
                $("#humidity_pid").html("PID : " + data["PID"]);
                $("#humidity_vid").html("VID : " + data["VID"]);
                $("#humidity_uuid").html("UUID : " + data["UUID"]);
            },
        }); 
    };
    function get_pm_1_0_infomation() {
        $.ajax({
            url: '/get_sensor_infomation',
            data : {sensor_name: "PMS5003T_PM1_0", csrfmiddlewaretoken: document.getElementsByName('csrfmiddlewaretoken')[0].value},
            type: 'post',
            success: function(data) {
                //console.log(data["PID"]);
                $("#pm_1_0_pid").html("PID : " + data["PID"]);
                $("#pm_1_0_vid").html("VID : " + data["VID"]);
                $("#pm_1_0_uuid").html("UUID : " + data["UUID"]);
            },
        }); 
    };
    function get_pm_2_5_infomation() {
        $.ajax({
            url: '/get_sensor_infomation',
            data : {sensor_name: "PMS5003T_PM2_5", csrfmiddlewaretoken: document.getElementsByName('csrfmiddlewaretoken')[0].value},
            type: 'post',
            success: function(data) {
                //console.log(data["PID"]);
                $("#pm_2_5_pid").html("PID : " + data["PID"]);
                $("#pm_2_5_vid").html("VID : " + data["VID"]);
                $("#pm_2_5_uuid").html("UUID : " + data["UUID"]);
            },
        }); 
    };
    function get_pm10_infomation() {
        $.ajax({
            url: '/get_sensor_infomation',
            data : {sensor_name: "PMS5003T_PM10", csrfmiddlewaretoken: document.getElementsByName('csrfmiddlewaretoken')[0].value},
            type: 'post',
            success: function(data) {
                //console.log(data["PID"]);
                $("#pm10_pid").html("PID : " + data["PID"]);
                $("#pm10_vid").html("VID : " + data["VID"]);
                $("#pm10_uuid").html("UUID : " + data["UUID"]);
            },
        }); 
    };

    // Once
    get_sys_version();
    mqtt_get_uri();
    
    // Repeat
    setInterval(get_humidity_infomation, 500);
    setInterval(get_temperature_infomation, 500);
    setInterval(get_pm_1_0_infomation, 500);
    setInterval(get_pm_2_5_infomation, 500);
    setInterval(get_pm10_infomation, 500);
    setInterval(read_humidity, 500);
    setInterval(read_humidity_time, 500);
    setInterval(read_temperature, 500);
    setInterval(read_temperature_time, 500);
    setInterval(read_pm_1_0, 500);
    setInterval(read_pm_2_5, 500);
    setInterval(read_pm10, 500);
    setInterval(read_pm_1_0_time, 500);
    setInterval(read_pm_2_5_time, 500);
    setInterval(read_pm10_time, 500);
    setInterval(mqtt_server_status, 500);
});