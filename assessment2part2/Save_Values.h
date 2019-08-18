#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Save_Values
{
public:
	Save_Values();
	~Save_Values();
	//function used for the simple purposes of taking input from 
	//input file and allocating the data to usable variables and 
	//data structures. 
	int * saveFromInput(int *size);
};