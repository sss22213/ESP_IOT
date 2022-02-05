$(function() {
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
    function read_humidity_time() {
        $.ajax({
            url: '/get_humidity_time',
            type: 'get',
            success: function(data) {
                $("#humidity_update_time").html("Updated " + data + " seconds ago");
            },
        }); 
        
    };
    function read_temperature_time() {
        $.ajax({
            url: '/get_temperature_time',
            type: 'get',
            success: function(data) {
                $("#temperature_update_time").html("Updated " + data + " seconds ago");
            },
        }); 
        
    };
    function mqtt_server_status() {
        $.ajax({
            url: '/get_mqtt_status',
            type: 'get',
            success: function(data) {
                if (data == 1) {
                    $("#mqtt_server_status").html("Connected to MQTT server");
                } else {
                    $("#mqtt_server_status").html("Disconnect");
                }
            },
            error: function() {
                $("#mqtt_server_status").html("Disconnect");
            },
        }); 
        
    };
    setInterval(read_humidity, 500);
    setInterval(read_humidity_time, 500);
    setInterval(read_temperature, 500);
    setInterval(read_temperature_time, 500);
    setInterval(mqtt_server_status, 500);
});