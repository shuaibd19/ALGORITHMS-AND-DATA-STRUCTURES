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
	//This function takes from provided input file and using pointers stores those values on the system
	//and also returns the very last line of the input file that should be an array
	int * saveFromInput(int *order, int *complx, int *size);
};

Save_Values::Save_Values()
{
}

Save_Values::~Save_Values()
{
}

int * Save_Values::saveFromInput(int *order, int *complx, int *size)
{
	int count = 0;
	static int *items;
	ifstream myFile("input-a1q1.txt");
	if (myFile.is_open())
	{
		while (!myFile.eof())
		{
			myFile >> *order;
			//Error checking for line 1 to make sure that number is binary
			if (*order < 0 || *order > 1)
			{
				cout << "Error: Number provided in line 1 must be 1 or 0\n";
				exit(EXIT_FAILURE);
			}

			myFile >> *complx;
			//Error checking for line 2 to make sure that number is binary
			if (*complx < 0 || *complx > 1)
			{
				cout << "Error: Number provided in line 2 must be 1 or 0\n";
				exit(EXIT_FAILURE);
			}

			myFile >> *size;
			//Error checking for line 3 to make sure that size of array cannot be less than 0
			if (*size < 0)
			{
				cout << "Error: Size of array cannot be less than 0.\n";
				exit(EXIT_FAILURE);
			}

			items = new int[*size];
			for (int i = 0; i < *size; i++)
			{
				myFile >> items[i];
				count++;
			}
			//Error checking to make sure that the number of elements in the array match the number provided
			//in the previous line of input
			if (count < *size)
			{
				cout << "Error: Number of elements in array does not match provided input.\n";
				exit(EXIT_FAILURE);
			}
			
		}
		myFile.close();
	}
	else
	{
		cout << "Error: No file found for reading input\n";
	}
	return items;
}
