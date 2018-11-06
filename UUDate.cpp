/*
* UUDate.cpp
*
* Version information
* Author: Anthony McGuigan
* Date: 05/11/2018
* Description: This file is the implementation file for the UUDate class and defines (implements) the functions of the class
*
* Copyright notice - aye
*/


#include "UUDate.h"
#include <string>
#include <iostream>

UUDate::UUDate() {
	//Initialise the date to 01/01/2000
	day_ = 1;
	month_ = 1;
	year_ = 2000;
}

UUDate::UUDate(int day, int month, int year) {
	SetMonth(month);
	SetDay(day);
	SetYear(year);
	GetDate();
}

UUDate::UUDate(std::string date) {
	//TODO - Add your implementation here
	//PARSE CODE

}

void UUDate::IncrementDate() {
	int dayINC = GetDay();
	int monthINC = GetMonth();
	int yearINC = GetYear();

	//======31 days
	if (monthINC == 1 || monthINC == 3 || monthINC == 5 || monthINC == 7 || monthINC == 8 || monthINC == 10 || monthINC == 12)
	{

		if (dayINC == 31) {

			dayINC = 1;
			monthINC++;
			if (monthINC > 12) {
				monthINC = 1;
				yearINC++;
			}
		}
		else {
			dayINC++;
		}
	}

	//======30 days
	else if (monthINC == 4 || monthINC == 6 || monthINC == 9 || monthINC == 11)
	{
		if (dayINC > 30) {
			dayINC = 1;
			monthINC++;
		}
		else {
			dayINC++;
		}
	}


	//======other
	else if (monthINC == 2)
	{
		if ((yearINC % 4) == 0) {

			//NOT LEAP YEAR
			if ((yearINC % 100) == 0)
			{
				if (dayINC > 28) {
					dayINC = 1;
					monthINC++;
				}
				else {
					dayINC++;
				}
			}

			//LEAPYEAR
			else
			{
				if (dayINC > 29) {
					dayINC = 1;
					monthINC++;
				}
				else {
					dayINC++;
				}
			}
		}

		else if ((yearINC % 4) != 0) {
			if (dayINC = 28) {
				dayINC = 1;
				monthINC++;
			}
			else {
				dayINC++;
			}
		}
	}

	//=====SETTING DATE======
	SetDay(dayINC);
	SetMonth(monthINC);
	SetYear(yearINC);
	GetDate();
}

int UUDate::Between(UUDate date) {
	//TODO - Add your implementation here
	return 0;
}

int UUDate::GetDay() const {
	return day_;
}

void UUDate::SetDay(int day) {
	day_ = day;
}

int UUDate::GetMonth() const {
	return month_;
}

void UUDate::SetMonth(int month) {
	if (month >= 1 && month <= 12) {
		month_ = month;
	}
	else {
		month_ = 1;
	}
}

int UUDate::GetYear() const {
	return year_;
}

void UUDate::SetYear(int year) {
	if (year > 0) {
		year_ = year;
	}
	else {
		year = 2000;
	}
}

std::string UUDate::GetDate() {
	std::string strDay = std::to_string(GetDay());
	std::string strMonth = std::to_string(GetMonth());
	std::string strYear = std::to_string(GetYear());

	date_ = strDay + "/" + strMonth + "/" + strYear;
	return date_;
}
