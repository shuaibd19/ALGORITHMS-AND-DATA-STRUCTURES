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
	//Remember to use pointers for your dinamic allocation
	int *items;
	ifstream myfile(fileName);
	if (myfile.is_open())
	{
		while (!myfile.eof())
		{
			myfile >> sortOrder;
			cout << sortOrder << endl;
			//condition for first if statement
			myfile >> complexity;
			cout << complexity << endl;
			//condition for second if statement
			myfile >> sizeOfArray;
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
		cout << "Error: File Open for read";
	}
}
