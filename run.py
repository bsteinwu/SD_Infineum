# Importing Libraries
#from pickle import FALSE
import serial
import time
on = True

arduino = serial.Serial(port='COM3', baudrate=115200, timeout=.1)

print("Testing")
def write_read(x):
    arduino.write(bytes(x, 'utf-8'))
    time.sleep(0.05)
    data = arduino.readline()
    return data

while on == True:
    num = input("Enter a command: ") # Taking input from user
    #print(num)
    if num == 24:
        on = False
    arduino.write(bytes(num, 'utf-8'))
    #print(value) # printing the value
    
    if num == "LED":
        print("LED mode")
        time.sleep(0.1)
        led = input("Enter an LED to light: ")
        arduino.write(bytes(led, 'utf-8'))

    if num == "Sensor" or num == "sensor":
        print("Sensor reading mode")
        time.sleep(0.1)
        sen = input("Enter a sensor to read: ")
        arduino.write(bytes(sen, 'utf-8'))
        time.sleep(1.5)
        sensorReading = arduino.readline()
        #sensorReading = arduino.read(arduino.inWaiting())
        time.sleep(0.1)
        print(sensorReading.decode())