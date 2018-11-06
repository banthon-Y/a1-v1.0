/*
* main.cpp
*
* Version information
* Author: TODO - Add your name here
* Date: TODO - Add date you started working on the code
* Description: This file is the driver for the project, use it to test your code.
*
* Copyright notice -
*/

#pragma once 
#include "UUDate.h"
#include <iostream>

using namespace std;

int main() {

	//TODO - Add your test code here

	//Remember to test your code thoroughly before running it against the tests in github
	UUDate date(30, 8, 1997);
	cout << date.GetDate() << endl;
	date.IncrementDate();
	cout << "New: " << date.GetDate() << endl;
	return 0;
}