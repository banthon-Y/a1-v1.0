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
#include <iostream>
#include <sstream>
#include <array>
#include <string>

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
	//split code from the string to intergers
	std::string holdDate[3];
	std::stringstream ss(date);
	std::string token;
	
	int i = 0;
	
	while (std::getline(ss, token, '/')) {
		holdDate[i] = token;
		i++;
	}
	SetDay(std::stoi(holdDate[0]));
	SetMonth(std::stoi(holdDate[1]));
	SetYear(std::stoi(holdDate[2]));
}

void UUDate::IncrementDate() {
	int dayINC = GetDay();
	int monthINC = GetMonth();
	int yearINC = GetYear();
	int numDays = GetThreshold(monthINC);

	//..months 31 days
	if (numDays == 31) {
		if (dayINC > 30) {
			dayINC = 1;
			monthINC++;
			if (monthINC > 12) {
				yearINC++;
			}
		}
		else {
			dayINC++;
		}
	}

	//..months 30 days
	else if (numDays == 30) {
		if (dayINC > 29) {
			dayINC = 1;
			monthINC++;
		}
		else {
			dayINC++;
		}
	}
	
	//..february
	else if (numDays == 28) {
		if ((yearINC % 4) == 0) {
			if (dayINC > 28) {
				dayINC = 1;
				monthINC++;
			}
			else {
				dayINC++;
			}
		}
		else {
			if (dayINC > 27) {
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
	//initialize variables
	int a; //used in deciding which date is bigger
	int yearB = date.GetYear();
	int monthB = date.GetMonth();
	int dayB = date.GetDay();
	//initializing the 2 dates into variables for ease
	std::string dateB = GetDate();
	std::string dateA = date.GetDate();
	
	//find which date is bigger--------         a=1 means inputted year is bigger       a=0 means inputted date is smaller
	if (date.GetYear() > GetYear()) {
		a = 1;
	}
	else if (date.GetYear() < GetYear()) {
		a = 0;
	}
	else if (date.GetYear() == GetYear()) 
	{
		if (date.GetMonth() > GetMonth()) {
			a = 1;
		}
		else if (date.GetMonth() < GetMonth()) {
			a = 0;
		}
		else if (date.GetMonth() == GetMonth()) 
		{
			if (date.GetDay() > GetDay()) {
				a = 1;
			}
			else if (date.GetDay() < GetDay()) {
				a = 0;
			}
		}
	}

	int count = 0;
	//Check for a change in the 2 dates by counting incriments
	if (a==1) {
		while (dateA.compare(GetDate()) != 0)
		{
			IncrementDate();
			count++;
		}
	}

	//Check for a Change in the 2 dates by counting incriments
	else {
		while (dateB.compare(date.GetDate()) != 0)
		{
			date.IncrementDate();
			count++;
		}
	}

	return count;
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

int UUDate::GetThreshold(int month) {
	int days_, i;
	i = (month - 1);
	days_ = monthThreshold_[i];
	return days_;
}