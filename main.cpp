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

	UUDate myDate("30/08/1997");
	 
	UUDate myDate2("30/08/1997");

	std::cout << myDate.Between(myDate2) << std::endl;



	//Remember to test your code thoroughly before running it against the tests in github
	
	return 0;
}