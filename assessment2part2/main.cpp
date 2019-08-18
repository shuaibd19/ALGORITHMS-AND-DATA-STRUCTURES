#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "Gen_Ran_Inp.h"
#include "Save_Values.h"
#include "MaxHeap.h"

using namespace std;


int main()
{
	//creating objects of the various classes
	//in order to be used 
	Gen_Ran_Inp ran;
	Save_Values save;
	MaxHeap maxHeap;

	//initialising boolean values to check functions
	//from various classses are working
	bool didBuildMaxHeap = false;
	bool didGenerate = false;
	didGenerate = ran.writeRanInp();

	//defining two variabls one being an integer value to represent 
	//the first value in the first line of the input text the second
	//one being a dynamic array to take in the stream of numbers
	//in the second line of the input text
	int numElements = 0;
	int *items;

	items = save.saveFromInput(&numElements);

	//printing out to console for debugging purposes
	cout << "Number of elements: " << numElements << endl;
	cout << "Elements: " << endl;
	for (int i = 0; i < numElements; i++)
	{
		if (i == numElements - 1)
		{
			cout << items[i];
		}
		else
		{
			cout << items[i] << " ";
		}

	}

	cout << "\n\n";

	//calling upon the maxheap function to work on the provided array "items"
	didBuildMaxHeap = maxHeap.buildHeap(items, numElements);


	//outputting to a file using 2 for loops to create a right triangle 
	//effect. I know this isn't what was meant by the assignment example 
	//as my one is just a cosmetic look whereas that one showed the actual
	//"heapifying" take place. unfortunately I was not able to implement that
	ofstream myFile;
	myFile.open("output-q2-a2.txt");

	for (int i = 0; i < numElements; i++)
	{
		for (int j = 0; j < i; j++)
		{
			myFile << items[j] << " ";
			cout << items[j] << " ";
		}
		myFile << endl;
		cout << endl;
	}

	myFile.close();

	return 0;
}
