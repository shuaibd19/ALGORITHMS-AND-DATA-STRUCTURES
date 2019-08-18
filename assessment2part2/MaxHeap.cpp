#include "MaxHeap.h"

void MaxHeap::heapify(int * arr, int iterator, int numElements)
{
	//used to keep track of the largest value for sorting purposes
	int biggestVal = iterator;
	int leftChild = (2 * iterator + 1);
	int rightChild = (2 * iterator + 2);

	//checking the if the left child is the larger than it's parent
	if (leftChild < numElements && arr[leftChild] > arr[biggestVal])
	{
		biggestVal = leftChild;
	}

	//checking the if the right child is the larger than it's parent
	if (rightChild < numElements && arr[rightChild] > arr[biggestVal])
	{
		biggestVal = rightChild;
	}
	if (biggestVal != iterator)
	{
		//in the case that either the left or right child has a larger 
		//value than it's parent then swap and run the function again
		//to check the next pairing
		swap(arr[iterator], arr[biggestVal]);
		heapify(arr, biggestVal, numElements);
	}
	
	
}

bool MaxHeap::buildHeap(int * arr, int numElements)
{
	//Building the max heap
	for (int i = ((numElements / 2) - 1); i >= 0; i--)
	{
		heapify(arr, i, numElements);
	}

	//Sorting out the max heap so that the root becomes the
	//the largest value once again
	for (int i = (numElements - 1); i >= 0; i--)
	{
		swap(arr[0], arr[i]);
		heapify(arr, i, numElements);
	}


	return true;
}

MaxHeap::MaxHeap()
{
}

MaxHeap::~MaxHeap()
{
}
