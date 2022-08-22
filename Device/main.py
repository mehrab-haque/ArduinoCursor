import serial
import time

serialPort = serial.Serial(
    port="COM6", baudrate=9600, bytesize=8, timeout=1, stopbits=serial.STOPBITS_ONE
)
serialString = ""
while 1:
    if serialPort.in_waiting > 0:
        serialString = serialPort.readline()
        try:
            data=int(serialString.decode("Ascii"))
            print(data)
        except:
            pass