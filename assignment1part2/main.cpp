//I was not able to get the delete from end function able to work within a loop
//order to timestamp therefore you will only get three lines of code with the times
//in milliseconds

#include <iostream>
#include <chrono>
#include "LinkedList.h"
#include "NumberGen.h"
#include "SaveNumber.h"
#include <time.h>
#include <fstream>
using namespace chrono;
using namespace std;

int main()
{
	//Seeding value for random number generator
	srand((unsigned)time(NULL));
	//Creating int to store value from file in its memory location
	int numberOfItems = 0;
	//NumberGen gen;
	//gen.writeRanInp();
	SaveNumber save;
	save.saveSize(&numberOfItems);
	cout << numberOfItems << endl;
	LinkedList lList;

	//Using chrono library functions to timestamp loops of various functions
	//from LinkedList class such as insertAtBeginning
	auto start1 = high_resolution_clock::now();
	for (int i = 0; i < numberOfItems; i++)
	{
		lList.insertAtBeginning(rand() % 10);
	}
	auto stop1 = high_resolution_clock::now();
	auto insertB = duration_cast<milliseconds>(stop1 - start1);
	cout << insertB.count() << endl << endl;

	auto start2 = high_resolution_clock::now();
	for (int i = 0; i < numberOfItems; i++)
	{
		lList.deleteFromBeginning();
	}
	auto stop2 = high_resolution_clock::now();
	auto deleteB = duration_cast<milliseconds>(stop2 - start2);
	cout << deleteB.count() << endl << endl;

	auto start3 = high_resolution_clock::now();
	for (int i = 0; i < numberOfItems; i++)
	{
		lList.insertAtEnd(rand()%10);
	}
	auto stop3 = high_resolution_clock::now();
	auto insertE = duration_cast<milliseconds>(stop3 - start3);
	cout << insertE.count() << endl << endl;


	//Printing the various values in milliseconds outputted from the 
	//timestamping to an output.txt file
	ofstream myFile;
	myFile.open("output-a1q2.txt");
	myFile << insertB.count() << endl;
	myFile << insertE.count() << endl;
	myFile << deleteB.count() << endl;
	myFile.close();


	
	return 0;
}
