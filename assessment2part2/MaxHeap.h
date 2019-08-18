//reference material for assessment task: https://www.programiz.com/dsa/heap-sort
// https://algorithmtutor.com/Data-Structures/Tree/Binary-Heaps/
// https://www.tutorialspoint.com/data_structures_algorithms/heap_data_structure.htm

#pragma once
#include <iostream>
#include <conio.h>
using namespace std;

class MaxHeap
{
public:

	//recursive function to make sure that the rules of max heap
	//that being the parent node's value of allways being larger than
	//it's children's
	void heapify(int *arr, int iterartor, int numElements);
	//this function is used in the actual construction of a max heap
	//by utilising the heapify function above as well
	bool buildHeap(int *arr, int numElements);
	MaxHeap();
	~MaxHeap();
};