#pragma once

#include <iostream>
#include <ctime>
#include "typedef.h"
#include <Windows.h>
#include "defines.h"

using namespace std;

UCI months = 12;
UCI days = 7;

const char months_array[months][months] = { 
	"January", 
	"February", 
	"March", 
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"October", 
	"November",
	"December"
};

const char week_days[days][months] = { 
	"Sunday", 
	"Monday", 
	"Tuesday",
	"Wednesday", 
	"Thursday", 
	"Friday", 
	"Saturday" 
};

class DateTime {
	time_t _now;
	struct tm _nowLocal;

public:
	DateTime() : 
	_now(time(nullptr)),
	_nowLocal(*localtime(&_now)) {
		// free space
	}

	void CurrentTime() const {
		UCI currentYear = 1900 + Year();
		UCI currentMonth = Month() + 1;
		cout << "[Current time]: <";
		if (Hours() < 10)
		{
			cout << "0";
		}
		cout << Hours() << ":";
		if (Minutes() < 10)
		{
			cout << "0";
		}
		cout << Minutes() << ":";
		if (Seconds() < 10)
		{
			cout << "0";
		}
		cout << Seconds() << ">___<Hours/Mins/Seconds>_____________________________\n";
		cout << "[Current date]: <";
		if (MonthDay() < 10)
		{
			cout << "0";
		}
		cout << MonthDay() << ":";
		if (currentMonth < 10)
		{
			cout << "0";
		}
		cout << currentMonth << ":" << currentYear << ">___<Day/Month/Year>________________________________\n";
		cout << "[Current day]: <" << week_days[WeekDay()] << ">____________________________________________________________\n";
		cout << "[Current month]: <" << months_array[Month()] << ">____________________________________________________________\n";
		cout << "[Information]: <Days since January 1 of " << currentYear << ": " << DaysSince1900() << ">__________________________________________\n";
		cout << "[Daylight Saving Time Flag]: <";
		if (IsDayLight() > 0)
		{
			cout << "IN EFFECT";
		}
		else if (IsDayLight() == 0)
		{
			cout << "NOT IN EFFECT";
		}
		else
		{
			cout << "INFORMATION NOT AVAILABLE";
		}
		cout << ">_______________________________________________________\n";
		cout << endl;
	}

	void MainLoop(const int &times) {
		for(int i = 0; i < times; i++) {
			CLS;
			DateTime local_time;
			local_time.CurrentTime();
			Sleep(1000);
		}
	}

	int Seconds() const {
		return _nowLocal.tm_sec;
	}

	int Minutes() const {
		return _nowLocal.tm_min;
	}

	int Hours() const {
		return _nowLocal.tm_hour;
	}

	int MonthDay() const {
		return _nowLocal.tm_mday;
	}

	int Month() const {
		return _nowLocal.tm_mon;
	}

	int Year() const {
		return _nowLocal.tm_year;
	}

	int WeekDay() const {
		return _nowLocal.tm_wday;
	}

	int DaysSince1900() const {
		return _nowLocal.tm_yday;
	}

	int IsDayLight() const {
		return _nowLocal.tm_sec;
	}
};

/*
	tm_sec	int	seconds after the minute	0-60*
	tm_min	int	minutes after the hour	0-59
	tm_hour	int	hours since midnight	0-23
	tm_mday	int	day of the month	1-31
	tm_mon	int	months since January	0-11
	tm_year	int	years since 1900
	tm_wday	int	days since Sunday	0-6
	tm_yday	int	days since January 1	0-365
	tm_isdst int Daylight Saving Time flag
*/