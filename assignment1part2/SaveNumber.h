#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class SaveNumber
{
public:
	SaveNumber();
	~SaveNumber();
	//Function looks for a number in a file and saves it to a memory address
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
	//Look for a file with a specific name
	ifstream myFile("input-a1q2.txt");
	if (myFile.is_open())
	{
		//Checking to see if it reaches the end of the file
		while (!myFile.eof())
		{
			//assign the integer found to the one provided in the parameters
			myFile >> *numOfElm;
		}
		myFile.close();
	}
	//in the case of no file by that name being found report error
	else
	{
		cout << "ERROR: No File found for reading Input\n";
	}
}
