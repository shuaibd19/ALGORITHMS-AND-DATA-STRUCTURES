#include "Save_Values.h"

Save_Values::Save_Values()
{
}

Save_Values::~Save_Values()
{
}

int * Save_Values::saveFromInput(int *size)
{
	static int *items;
	ifstream myFile("input-q1a2.txt");
	if (myFile.is_open())
	{
		while (!myFile.eof())
		{
			myFile >> *size;
			items = new int[*size];
			for (int i = 0; i < *size; i++)
			{
				myFile >> items[i];
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
