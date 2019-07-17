#include <iostream>
#include <string>
#include "Gen_Ran_Inp.h"
#include "Save_Values.h"
using namespace std;

void printArray(int *items, int size);
void bubbleSortA(int *arrayToSort, int size);
void bubbleSortD(int *arrayToSort, int size);

int main()
{
	int sortOrder = -2;
	int complexity = -2;
	int numOfItems = -2;
	int *items;
	Gen_Ran_Inp random;
	random.writeRanInput();
	
	Save_Values save;
	items = save.saveFromInput(&sortOrder, &complexity, &numOfItems);

	cout << sortOrder << endl;
	cout << complexity << endl;
	cout << numOfItems << endl;
	printArray(items, numOfItems);
	cout << endl;
	
	if (sortOrder == 0)
	{
		cout << endl;
		cout << "Ascending order chosen:\n";
		bubbleSortA(items, numOfItems);
		printArray(items, numOfItems);
		cout << endl;
	}
	else
	{
		cout << endl;
		cout << "Descending order chosen:\n";
		bubbleSortD(items, numOfItems);
		printArray(items, numOfItems);
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

//Reference to bubble sort algorithm: https://www.tutorialspoint.com/data_structures_algorithms/bubble_sort_program_in_c.htm
//Also https://mathbits.com/MathBits/CompSci/Arrays/Bubble.htm
void bubbleSortA(int *arrayToSort, int size)
{
	int temp = -1;
	for (int i = 1; i <= size; i++)
	{
		for (int j = 0; j < size-1; j++)
		{
			if (arrayToSort[j+1] < arrayToSort[j])
			{
				temp = arrayToSort[j];
				arrayToSort[j] = arrayToSort[j + 1];
				arrayToSort[j + 1] = temp;
			}
		}
	}
}

//Reference to bubble sort algorithm: https://www.tutorialspoint.com/data_structures_algorithms/bubble_sort_program_in_c.htm
//Also https://mathbits.com/MathBits/CompSci/Arrays/Bubble.htm

void bubbleSortD(int *arrayToSort, int size)
{
	int temp = -1;
	for (int i = 1; i <= size; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			if (arrayToSort[j + 1] > arrayToSort[j])
			{
				temp = arrayToSort[j];
				arrayToSort[j] = arrayToSort[j + 1];
				arrayToSort[j + 1] = temp;
			}
		}
	}
}
