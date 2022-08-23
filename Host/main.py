import json

import serial
import mouse
from win32api import GetSystemMetrics

screenWidth=GetSystemMetrics(0)
screenHeight=GetSystemMetrics(1)

serialPort = serial.Serial(
    port="COM6", baudrate=9600, bytesize=8, timeout=1, stopbits=serial.STOPBITS_ONE
)

serialString = ""
while 1:
    if serialPort.in_waiting > 0:
        serialString = serialPort.readline()
        try:
            accData=json.loads(str(serialString.decode("Ascii")))
            yEffective=accData['x']
            if yEffective<0:
                yEffective=0
            if yEffective>0.75:
                yEffective=0.75
            yPct=yEffective*100/0.75

            mouse.move(str(int(screenWidth/2)),str(int(screenHeight*(100-yPct)/100)))
            print(yPct)
        except Exception as e:
            print(e)
            pass