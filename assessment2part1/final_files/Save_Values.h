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
	//function used to store values from provided input file
	//and assigns it to useful variables and datastructures. 
	int * saveFromInput(int *size);
};