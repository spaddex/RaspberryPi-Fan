#!/usr/bin/env python3
import time
import os
import subprocess

def getCPUtemperature():
    res = os.popen('vcgencmd measure_temp').readline()
    return(res.replace("temp=","").replace("'C\n",""))
def fanON():
    subprocess.call('gpio -g mode 18 output && gpio -g write 18 1', shell=True)
    return()
def fanOFF():
    subprocess.call('gpio -g write 18 0', shell=True)
    return()
def getTEMP():
    CPU_temp = float(getCPUtemperature())
    if CPU_temp>45:
        fanON()
    else:
        fanOFF()
    return()
while 1:
    getTEMP()
    time.sleep(5)
