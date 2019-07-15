#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Read
{
public:
	Read();
	~Read();
	void readMyFile(string fileName);
	bool isAsceding(int sortOrder);
	bool isBestCase(int complexity);
	void isBinary(int num);
	void isPositive(int num);

private:

};

Read::Read()
{
}

Read::~Read()
{
}

void Read::readMyFile(string fileName)
{
	string line;
	int sortOrder = -1;
	int complexity = -1;
	int sizeOfArray = -1;
	//Remember to use pointers for your dynamic allocation
	int *items;
	ifstream myfile(fileName);
	if (myfile.is_open())
	{
		while (!myfile.eof())
		{
			myfile >> sortOrder;
			isBinary(sortOrder);
			cout << sortOrder << endl;
			//condition for first if statement
			myfile >> complexity;
			isBinary(complexity);
			cout << complexity << endl;
			//condition for second if statement
			myfile >> sizeOfArray;
			isPositive(sizeOfArray);
			cout << sizeOfArray << endl;
			//condition for third if statement
			items = new int[sizeOfArray];
			for (int i = 0; i < sizeOfArray; i++)
			{
				myfile >> items[i];
				cout << items[i] << " ";
			}
			cout << endl;
		}
		myfile.close();
	}
	
	else
	{
		cout << "Error: File Open for read\n";
	}
}

bool Read::isAsceding(int sortOrder)
{
	return(sortOrder == 0);
}

bool Read::isBestCase(int complexity)
{
	return(complexity == 0);
}

void Read::isBinary(int num)
{
	if (num < 0 || num > 1)
	{
		cout << "Error: Number must be binary!\n";
		exit(EXIT_FAILURE);
	}
}

void Read::isPositive(int num)
{
	if (num < 0)
	{
		cout << "Error: Number cannot be negative!\n";
		exit(EXIT_FAILURE);
	}
}
