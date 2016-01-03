#include <iostream>
#include <wiringPi.h>
#include <fstream>
#include <string>
#include <chrono>
#include <thread>

#define FAN 1

using namespace std;

int readTemp();


int main(void){
	
	int pinNumber=1; //Which pin/GPIO to use, pin1=GPIO18, see http://wiringpi.com/pins/
	wiringPiSetup(); //Initializing the lwiringPi lib
	pinMode(pinNumber,OUTPUT); //reading Pin-number + telling it to use output
	
	for(;;){
		readTemp();
		
	while(readTemp()>=36000){ //run when temp >= 36C (36*1000, so 38,5C = 385000 for example)
		std::this_thread::sleep_for(std::chrono::milliseconds(10000)); //wait 10 seconds
		digitalWrite(FAN,HIGH); //start fan
		}
		
	while(readTemp()<36000){
		std::this_thread::sleep_for(std::chrono::milliseconds(10000)); //wait 10 seconds
		digitalWrite(FAN,LOW); //turn off fan
		}
	}
}

int readTemp(){

	std::ifstream input_f("/sys/devices/virtual/thermal/thermal_zone0/temp");
	int temp;
	input_f >> temp;
	return temp;
	input_f.close();
	//cout << "Variablen x är " << x << endl;
}
