# RaspberryPi-Fan
Fans can be noisy, so why run them when the computer isn't that warm?

This is a program written in c++, which reads the temperature of the RPi, and activates the fan when needed. 

This was built on a Raspberry Pi running Kali Linux, but it might work on other distros as well. Might have to change the path
file which reads the temperature though. 

It requires the WiringPi library: https://github.com/WiringPi/WiringPi

Connect a fan with a transistor to GPIO 18, kind of like in the picture roccomuso got, but with GPIO18 instead, or change the code: https://github.com/roccomuso/rpi-fan

To compile, run "g++ -std=c++11 -o RPiFan main.cpp -lwiringPi"
