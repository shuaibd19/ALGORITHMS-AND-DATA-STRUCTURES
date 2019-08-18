#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "Gen_Ran_Inp.h"
#include "Save_Values.h"
#include "Binary_Tree.h"

using namespace std;


int main()
{
	Gen_Ran_Inp ran;
	Save_Values save;
	Binary_Tree avl;


	bool didGenerate = false;
	didGenerate = ran.writeRanInp();

	int numElements = 0;
	int *items;

	items = save.saveFromInput(&numElements);

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

	Node *root = nullptr;

	//inserting the data members from the items array 
	//into avl tree as nodes
	for (int i = 0; i < numElements; i++)
	{
		root = avl.insertNode(root, items[i]);
	}

	//calling upon the print function using BFS
	avl.printBFS(root);



	return 0;
}
