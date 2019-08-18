#include "Gen_Ran_Inp.h"

Gen_Ran_Inp::Gen_Ran_Inp()
{
	//constructer initializes all the values
	srand((unsigned int)time(NULL));
	numElements = rand() % 100;
	items = new int[numElements];
	for (int i = 0; i < numElements; i++)
	{
		items[i] = rand() % 100;
	}
}

Gen_Ran_Inp::~Gen_Ran_Inp()
{
}

bool Gen_Ran_Inp::writeRanInp()
{
	//outputting randomly generated values into a file

	ofstream myFile;
	myFile.open("input-q1a2.txt");
	myFile << numElements << endl;
	for (int i = 0; i < numElements; i++)
	{
		//Making sure that there is no extra space after the last item
		if (i == (numElements - 1))
		{
			myFile << items[i];
		}
		else
		{
			myFile << items[i] << " ";
		}
	}
	myFile.close();
	return true;
}