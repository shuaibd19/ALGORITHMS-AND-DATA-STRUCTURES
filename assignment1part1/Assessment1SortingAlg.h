#pragma once

class SortingAlg
{
public:
	SortingAlg();
	~SortingAlg();
	//Ascending Bubble Sort Best Case
	void bubbleSortA(int *arrayToSort, int size);
	//Descending Bubble Sort Best Case
	void bubbleSortD(int *arrayToSort, int size);
	//Ascending Selection Sort for Worst Case
	void selectionSortA(int *arrayToSort, int size);
	//Descending Selection Sort for Worst Case
	void selectionSortD(int *arrayToSort, int size);
};

SortingAlg::SortingAlg()
{
}

SortingAlg::~SortingAlg()
{
}


//Reference to bubble sort algorithm: https://www.tutorialspoint.com/data_structures_algorithms/bubble_sort_program_in_c.htm
//Also https://mathbits.com/MathBits/CompSci/Arrays/Bubble.htm
void SortingAlg::bubbleSortA(int *arrayToSort, int size)
{
	int temp = -1;
	for (int i = 1; i <= size; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			if (arrayToSort[j + 1] < arrayToSort[j])
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

void SortingAlg::bubbleSortD(int *arrayToSort, int size)
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


//Reference for this code: https://www.geeksforgeeks.org/selection-sort/
void SortingAlg::selectionSortA(int *arrayToSort, int size)
{
	int temp = -1;
	int minimum = 0;

	for (int i = 0; i < size - 1; i++)
	{
		minimum = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arrayToSort[j] < arrayToSort[minimum])
			{
				minimum = j;
			}
		}
		if (minimum != i)
		{
			temp = arrayToSort[minimum];
			arrayToSort[minimum] = arrayToSort[i];
			arrayToSort[i] = temp;
		}
	}
}

//Reference for this code: https://mathbits.com/MathBits/CompSci/Arrays/Selection.htm
void SortingAlg::selectionSortD(int *arrayToSort, int size)
{
	int temp = -1;
	int maximum = -1;

	for (int i = size - 1; i > 0; i--)
	{
		maximum = 0;
		for (int j = 1; j <= i; j++)
		{
			if (arrayToSort[j] < arrayToSort[maximum])
			{
				maximum = j;
			}
		}
		temp = arrayToSort[maximum];
		arrayToSort[maximum] = arrayToSort[i];
		arrayToSort[i] = temp;
	}
}
