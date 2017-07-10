//Naveen Janarthanan
//CSC 2430 
//2/22/2017

#pragma once

#include "Time.h"
#include <iostream>
#include <time.h>
#include <sstream>
#include <iomanip>
#include <string>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;
class Time
{
public:
	//constructors
	Time();
	Time(const int hours, const int mins, const int secs);

	//access methods
	double getSeconds();
	double setSeconds(int newSec);
	double getMinutes();
	double setMinutes(int newMin);
	double getHours();
	double setHours(int newHour);
	void incrementSeconds(int iSec);
	void incrementMinutes(int iMin);
	void incrementHours(int iHour);
	string get24HourFormat();
	string get12HourAmPmFormat();


private:
	int mHour;
	int hour, min, sec;
	double tSec, tHour;

};

