#include <iostream>
#include <wiringPi.h>
#include <fstream>
#include <string>
#include <chrono>
#include <thread>
using namespace std;

int grader();
int wiringPiSetup (void) ; //ser till att wiring.h laddas
int main()
{
	int pinNumber=18;


    while(grader()>35000){
		std::this_thread::sleep_for(std::chrono::milliseconds(2000));
		cout << "Det är " << grader()/1000 << " grader" << endl;
		pinMode(pinNumber,OUTPUT);
		digitalWrite(pinNumber,0);}
		grader();

	while(grader()<35000){
		std::this_thread::sleep_for(std::chrono::milliseconds(2000));
		cout << "Det är " << grader()/1000 << " grader" << endl;
		pinMode(pinNumber,OUTPUT);
		digitalWrite(pinNumber,1);}
		grader();
}

int grader(){
	//Följande kodblock läser graderna :)
	int x;
	std::ifstream input_f("/sys/devices/virtual/thermal/thermal_zone0/temp");
	std::string temp_str;
	std::getline(input_f,temp_str);
	x = atoi(temp_str.c_str());
	cout << "Variablen x är " << x << endl;
	return x;
	main();
}
