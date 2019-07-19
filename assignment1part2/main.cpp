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
	typedef high_resolution_clock Clock;
	srand((unsigned)time(NULL));
	int numberOfItems = 0;
	//NumberGen gen;
	//gen.writeRanInp();
	SaveNumber save;
	save.saveSize(&numberOfItems);
	cout << numberOfItems << endl;
	LinkedList lList;

	auto start1 = Clock::now();
	for (int i = 0; i < numberOfItems; i++)
	{
		lList.insertAtBeginning(rand() % 10);
	}
	auto stop1 = Clock::now();
	auto duration1 = duration_cast<milliseconds>(stop1 - start1);
	cout << duration1.count() << endl << endl;

	auto start2 = Clock::now();
	for (int i = 0; i < numberOfItems; i++)
	{
		lList.deleteFromBeginning();
	}
	auto stop2 = Clock::now();
	auto duration2 = duration_cast<milliseconds>(stop2 - start2);
	cout << duration2.count() << endl << endl;

	auto start3 = Clock::now();
	for (int i = 0; i < numberOfItems; i++)
	{
		lList.insertAtEnd(rand()%10);
	}
	auto stop3 = Clock::now();
	auto duration3 = duration_cast<milliseconds>(stop3 - start3);
	cout << duration3.count() << endl << endl;

	ofstream myFile;
	myFile.open("output-a1q2.txt");
	myFile << duration1.count() << endl;
	myFile << duration3.count() << endl;
	myFile << duration2.count() << endl;
	//myFile << duration4.count() << endl;
	myFile.close();

	auto start4 = Clock::now();
	for (int i = 0; i < numberOfItems; i++)
	{
		lList.deleteFromEnd();
	}
	auto stop4 = Clock::now();
	auto duration4 = duration_cast<milliseconds>(stop4 - start4);
	cout << duration4.count() << endl;

	
	return 0;
}
