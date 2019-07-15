#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

using namespace std;

class Ran_Write
{
public:
	Ran_Write();
	~Ran_Write();
	void writeToFile(string fileName);
private:
	int sortOrder;
	int complexity;
	int sizeOfArray;
	int *items;
};

Ran_Write::Ran_Write()
{
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

Ran_Write::~Ran_Write()
{
}

void Ran_Write::writeToFile(string fileName)
{
	//Outputting all of this to the file

	ofstream myfile;
	myfile.open(fileName);
	myfile << sortOrder << endl;
	myfile << complexity << endl;
	myfile << sizeOfArray << endl;
	for (int i = 0; i < sizeOfArray; i++)
	{
		myfile << items[i] << " ";
	}
	myfile.close();
}
