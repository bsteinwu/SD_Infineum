
"""
import serial
import time

arduino = serial.Serial(port='COM4', baudrate=115200, timeout=.1)
def arduino_write(num):
    arduino = serial.Serial(port='COM4', baudrate=115200, timeout=.1)
    
    while True:
        time.sleep(0.1)
        arduino.write(bytes(44, 'utf-8'))
"""