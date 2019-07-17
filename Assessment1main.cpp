#include <iostream>
#include <string>
#include <chrono>
#include "Gen_Ran_Inp.h"
#include "Save_Values.h"
#include "SortingAlg.h"
using namespace std::chrono;
using namespace std;

void printArray(int *items, int size);

int main()
{
	int sortOrder = -2;
	int complexity = -2;
	int numOfItems = -2;
	int *items;

	SortingAlg sorting;
	Gen_Ran_Inp random;
	random.writeRanInput();
	Save_Values save;
	items = save.saveFromInput(&sortOrder, &complexity, &numOfItems);

	cout << sortOrder << endl;
	cout << complexity << endl;
	cout << numOfItems << endl;
	printArray(items, numOfItems);
	cout << endl;

	if (sortOrder == 0 && complexity == 0)
	{
		cout << endl;
		cout << "Bubble Sort: Ascending order chosen:\n";
		auto start = high_resolution_clock::now();
		for (int i = 0; i < 10000; i++)
		{
			sorting.bubbleSortA(items, numOfItems);
		}
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<milliseconds>(stop - start);
		printArray(items, numOfItems);
		cout << "\n\n";
		cout << "count has taken 0.00" << duration.count() << " milliseconds - to execute\n";
		cout << endl;
	}
	else if(sortOrder == 1 && complexity == 0)
	{
		cout << endl;
		cout << "Bubble Sort: Descending order chosen:\n";
		auto start = high_resolution_clock::now();
		for (int i = 0; i < 10000; i++)
		{
			sorting.bubbleSortD(items, numOfItems);
		}
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<milliseconds>(stop - start);
		printArray(items, numOfItems);
		cout << "\n\n";
		cout << "count has taken 0.00" << duration.count() << " milliseconds - to execute\n";
		cout << endl;
	}
	
	else if (sortOrder == 0 && complexity == 1)
	{
		cout << endl;
		cout << "Selection Sort: Ascending order chosen:\n";
		auto start = high_resolution_clock::now();
		for (int i = 0; i < 10000; i++)
		{
			sorting.selectionSortA(items, numOfItems);
		}
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<milliseconds>(stop - start);
		printArray(items, numOfItems);
		cout << "\n\n";
		cout << "count has taken 0.00" << duration.count() << " milliseconds - to execute\n";
		cout << endl;
	}

	else if (sortOrder == 1 && complexity == 1)
	{
		cout << endl;
		cout << "Selection Sort: Descending order chosen:\n";
		auto start = high_resolution_clock::now();
		for (int i = 0; i < 10000; i++)
		{
			sorting.selectionSortD(items, numOfItems);
		}
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<milliseconds>(stop - start);
		printArray(items, numOfItems);
		cout << "\n\n";
		cout << "count has taken 0.00" << duration.count() << " milliseconds - to execute\n";
		cout << endl;
	}

	cout << endl;
	return 0;
}

void printArray(int *items, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (i == (size - 1))
		{
			cout << items[i];
		}
		else
		{
			cout << items[i] << " ";
		}
	}
}
