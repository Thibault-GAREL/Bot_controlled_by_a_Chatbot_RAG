import serial
import time

arduino = serial.Serial(port='/dev/ttyUSB0', baudrate=9600, timeout=1)
time.sleep(2)

message = "AV4RE5TG2TD3"
arduino.write(message.encode('utf-8')))
print("Message sent to Arduino:", message)

arduino.close()