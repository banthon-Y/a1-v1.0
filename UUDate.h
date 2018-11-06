/*
* UUDate.h
*
* Version information
* Author: Anthony McGuigan
* Date: 5/11/2018
* Description: This file is the header file for the UUDate class and declares the class interface
* NOTE: Do not change the signatures of the functions provided. You may add your own support functions
*
* Copyright notice - aye
*/

#pragma once

#include <string>
//You can include addition non-date/time related headers

class UUDate
{

private:
	//Date data
	int day_;
	int month_;
	int year_;
	int monthThreshold_[12]{ 31,28,31,30,31,31,31,31,31,31,30,31 };
	std::string date_;

public:
	UUDate(); //Default constructor sets date to 1/1/2000

			  //Non default constructors - remeber to validate input
	UUDate(int day, int month, int year);
	UUDate(std::string date); //Should accept "2/8/2018" or "02/08/2018

	int Between(UUDate date); //Return # days between object and date
	std::string GetDate(); //Return date as a string in correct format

						   //Getters and Setters, remember to validate input to setters
	int GetDay() const;
	void SetDay(int day);
	int GetMonth() const;
	void SetMonth(int month);
	int GetYear() const;
	void SetYear(int year);

	int GetThreshold(int month);

	void IncrementDate();//Increment the current date by one day

};