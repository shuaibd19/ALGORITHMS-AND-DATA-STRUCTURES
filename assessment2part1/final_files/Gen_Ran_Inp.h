#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>

using namespace std;

class Gen_Ran_Inp
{
public:
	Gen_Ran_Inp();
	~Gen_Ran_Inp();
	//generates a random input for and input file used for 
	//testing purposes
	bool writeRanInp();

private:
	int numElements;
	int *items;
};