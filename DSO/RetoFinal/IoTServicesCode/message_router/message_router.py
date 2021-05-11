import time
import paho.mqtt.client as paho
from measurement_register_interface import *
from device_register_interface import *
from load_preferences import getPreferences

current_temperature = "0"
current_temperature = 0
current_humidity = 0


def on_connect(client, userdata, flags, rc):
    if rc == 0:
        print("Connected success")
        client.subscribe("/uc3m/classrooms/leganes/myclass/temperature")
        client.subscribe("/uc3m/classrooms/leganes/myclass/humidity")
        client.subscribe("/uc3m/classrooms/leganes/myclass/device_info")
    else:
        print("Connected fail with code", {rc})


def on_message(client, userdata, message):
    global current_temperature, current_humidity
    print("received message =", str(message.payload.decode("utf-8")))
    if message.topic == "/uc3m/classrooms/leganes/myclass/temperature":
        raw_data = float(message.payload.decode("utf-8"))
        tempTime = raw_data.split(",")
        current_temperature = tempTime[0]
        current_time = tempTime[1]
        current_device = tempTime[2]
        data = {"temperature": current_temperature, "humidity": current_humidity, "date": current_time,
                "device": current_device}
        submit_data_to_store(data)
        print(data)
    if message.topic == "/uc3m/classrooms/leganes/myclass/humidity":
        raw_data = float(message.payload.decode("utf-8"))
        HumTime = raw_data.split(",")
        current_humidity = HumTime[0]
        current_time = HumTime[1]
        current_device = HumTime[2]
        data = {"temperature": current_temperature, "humidity": current_humidity, "date": current_time,
                "device": current_device}
        submit_data_to_store(data)
        print(data)
    if message.topic == "/uc3m/classrooms/leganes/myclass/device_info":
        raw_data = message.payload.decode("utf-8")
        idLocation = raw_data.split(",")
        r = idLocation[0]
        location = idLocation[1]
        date = idLocation[2]
        data = {"device": r, "location": location, "date": date} # Mirar como hacer lo de cambiar estados
        submit_device_info_to_store(data)
        print(data)


params = getPreferences("conf.yaml")
client = paho.Client()
client.username_pw_set(username=params["broker_user"], password=params["broker_pwd"])
client.on_connect = on_connect
client.on_message = on_message
print("connecting to broker ", params["broker_address"])
client.connect(params["broker_address"], params["broker_port"], params["broker_keep_alive"])  # connect
client.loop_forever()
