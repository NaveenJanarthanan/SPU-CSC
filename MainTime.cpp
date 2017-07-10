//Naveen Janarthanan
//CSC 2430 
//2/22/2017
#define _CRT_SECURE_NO_WARNINGS
#include "Time.h"
#include <iostream>
#include <iostream>
#include <string>
#include <time.h>
#include <sstream>
#include <iomanip>

using namespace std;

//Forward declaration
void testoutputformats(Time &t);

int main()
{

	
	Time alarmTime(22, 50, 30);

	string alarmString;

	alarmString = alarmTime.get24HourFormat();
	cout << alarmString << endl; 

	alarmString = alarmTime.get12HourAmPmFormat();
	cout << alarmString << endl; 

	//test outputs
	alarmTime.incrementSeconds(45);
	testoutputformats(alarmTime);


	alarmTime.incrementSeconds(200);
	testoutputformats(alarmTime);

	alarmTime.incrementMinutes(63);
	testoutputformats(alarmTime);
	
	alarmTime.incrementHours(24);
	testoutputformats(alarmTime);

	alarmTime.incrementHours(49);
	testoutputformats(alarmTime);

	alarmTime = Time(6, 30, 0);
	testoutputformats(alarmTime);

	alarmTime = Time(18, 30, 0);
	testoutputformats(alarmTime);

	alarmTime = Time(40, 30, 0); //Current Time
	testoutputformats(alarmTime);


	alarmTime = Time(7, 30, 0);
	testoutputformats(alarmTime);
	
	alarmTime.incrementHours(70);
	testoutputformats(alarmTime);

	alarmTime.incrementMinutes(50);
	testoutputformats(alarmTime);

	alarmTime.incrementSeconds(120);
	testoutputformats(alarmTime);

	alarmTime = Time(10, 30, 0);
	testoutputformats(alarmTime);


	alarmTime.incrementHours(1);
	testoutputformats(alarmTime);

	alarmTime.incrementMinutes(31);
	testoutputformats(alarmTime);


	return 0;

}

void testoutputformats(Time &t)
{
	string tmpString;

	tmpString = t.get24HourFormat();
	cout << "24 hour: "<< tmpString << endl;

	tmpString = t.get12HourAmPmFormat();
	cout << "12 hour: " << tmpString << endl;

	cout << endl;
}
