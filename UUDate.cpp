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
#include <sstream>
#include <vector>
#include <array>



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
	std::string holdDate[3];
	std::stringstream ss(date);
	std::string token;
	
	int i = 0;
	
	while (std::getline(ss, token, '/')) {
		holdDate[i] = token;
		std::cout << token << std::endl;
		i++;
	}
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

int UUDate::GetThreshold(int month) {
	int days_, i;
	i = (month - 1);
	days_ = monthThreshold_[i];
	return days_;
}