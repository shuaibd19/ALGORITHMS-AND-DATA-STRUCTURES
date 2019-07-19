#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class SaveNumber
{
public:
	SaveNumber();
	~SaveNumber();
	void saveSize(int *numOfElm);
};

SaveNumber::SaveNumber()
{
}

SaveNumber::~SaveNumber()
{
}

void SaveNumber::saveSize(int *numOfElm)
{
	ifstream myFile("input-a1q2.txt");
	if (myFile.is_open())
	{
		while (!myFile.eof())
		{
			myFile >> *numOfElm;
		}
		myFile.close();
	}
	else
	{
		cout << "ERROR: No File found for reading Input\n";
	}
}