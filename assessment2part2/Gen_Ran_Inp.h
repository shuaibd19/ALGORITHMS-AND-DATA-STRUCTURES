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
	//function used as a faux random input generator
	//within a defined range to test cases
	bool writeRanInp();

private:
	int numElements;
	int *items;
};