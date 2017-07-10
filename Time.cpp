//Naveen Janarthanan
//CSC 2430 
//2/22/2017

#define _CRT_SECURE_NO_WARNINGS
#include "Time.h"
#include <iostream>
#include <time.h>
#include <sstream>
#include <iomanip>
#include <string>
#include <cmath>


using namespace std;


Time::Time()
{
	//Current time
	time_t now;
	struct tm tstruct;

	time(&now);
	tstruct = *localtime(&now);

	hour = tstruct.tm_hour;
	min = tstruct.tm_min;
	sec = tstruct.tm_sec;

	
}

Time::Time(const int hours, const int mins, const int secs)
{
	//checks if the input is valid if not, set to current time
	if ((hours >= 0 && hours <= 24) &&(mins >= 0 && mins < 60) &&(secs >= 0 && sec <=60))
	{
		hour = hours;
		min = mins;
		sec = secs;

	}
	else {

		time_t now;
		struct tm tstruct;

		time(&now);
		tstruct = *localtime(&now);

		hour = tstruct.tm_hour;
		min = tstruct.tm_min;
		sec = tstruct.tm_sec;

	}
}

//access methods 

double Time::getSeconds()
{
	return(sec);
}

double Time::setSeconds(int newSec)
{

	return(newSec);
}

double Time::getMinutes()
{

	return(min);
}

double Time::setMinutes(int newMin)
{

	return(newMin);
}

double Time::getHours()
{
	return(hour);
}

double Time::setHours(int newHour)
{
	return(newHour);
}

void Time::incrementSeconds(int iSec)
{
	int tSec;
	tSec = iSec + sec;

	//increments the seconds if the value is greater than 0 and less than 60
	if (iSec >= 0 && tSec < 60)
	{ 
		sec += iSec;
	}
	//increments the seconds if the value is greater than 60
	else
	{
		sec = ((iSec + sec) % 60);
		incrementMinutes((iSec + sec) / 60);
	}

	
}

void Time::incrementMinutes(int iMin)
{
	
	//increments the minutes if the value of the minute is greater than 0 but less than 60
	if (iMin >= 0 && (iMin + min) < 60)
	{
		min += iMin;
	}

	//increments the minutes if the value is greater than 60
	else 
	{
		min = ((iMin + min) % 60);
		incrementHours((iMin + min) / 60);
	}
	
}

void Time::incrementHours(int iHour)
{
	
	//increcrements the hours if the the value is less than 24 and greater than 0
	if (hour >= 0 && ((hour + iHour) < 24))
	{
		hour = hour + iHour;
	}
	//increments the hour if the hour is greater than 24
	else
	{
		hour = (hour + iHour) % 24;
		
	}
	
}
string Time::get24HourFormat()
{
	ostringstream oss; // create variable to “write” to
					   // Output formatted data to the ostringstream variable (instead of cout)
	oss << setfill('0');
	oss << setw(2) << hour << ":" << setw(2) << min << ":" << setw(2) << sec;
	// Convert the ostringstream value into a standard string
	string result = oss.str();

	return(result);
}

string Time::get12HourAmPmFormat()
{
	ostringstream oss1; // create variable to “write” to
					   // Output formatted data to the ostringstream variable (instead of cout)

	string amORpm = "AM"; //create variable for am and pm

	int nHour;
	nHour = hour;
	
	//sets the am and pm based on the hour
	if (hour > 12) //if the hour is greater than 12
	{
		nHour = hour - 12; //substract 12 from the hour and set that equal to nHour
		amORpm = "PM"; //set the variable amORpm to PM
	}
	if (hour == 0 && min == 0 && sec == 0) //if all values equal 0 set to AM
	{ 
		
		amORpm = "AM";
	}

	if (hour == 12 && min == 0 && sec == 0) //If values are set to 12:00:00 set to PM
	{
		
		amORpm = "PM";
	}
	if (hour == 0) //if hour is equal to 0 make nHour = 12
	{
		nHour = 12; 
	}

	oss1 << setfill('0');
	oss1 << setw(2) << nHour << ":" << setw(2) << min << ":" << setw(2) << sec << setw(2)<< amORpm;
	// Convert the ostringstream value into a standard string
	string result = oss1.str();

	return (result);
}
