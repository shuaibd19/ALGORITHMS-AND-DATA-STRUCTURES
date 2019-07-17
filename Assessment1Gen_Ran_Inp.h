#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

using namespace std;

class Gen_Ran_Inp
{
public:
	Gen_Ran_Inp();
	~Gen_Ran_Inp();
	void writeRanInput();
private:
	int sortOrder;
	int complexity;
	int sizeOfArray;
	int *items;
};

Gen_Ran_Inp::Gen_Ran_Inp()
{
	//Constructor initialises all the values
	srand((unsigned int)time(NULL));
	sortOrder = rand() % 2;
	complexity = rand() % 2;
	sizeOfArray = rand() % 20;
	items = new int[sizeOfArray];
	for (int i = 0; i < sizeOfArray; i++)
	{
		items[i] = rand() % 100;
	}
}

Gen_Ran_Inp::~Gen_Ran_Inp()
{
}

void Gen_Ran_Inp::writeRanInput()
{
	//Outputting all of this to the file

	ofstream myFile;
	myFile.open("input-a1q1.txt");
	myFile << sortOrder << endl;
	myFile << complexity << endl;
	myFile << sizeOfArray << endl;
	for (int i = 0; i < sizeOfArray; i++)
	{
		//Making sure that there is no extra space after the last item
		if (i == (sizeOfArray - 1))
			{
				myFile << items[i];
			}
		else 
			{
				myFile << items[i] << " ";
			}
	}
	myFile.close();
}
