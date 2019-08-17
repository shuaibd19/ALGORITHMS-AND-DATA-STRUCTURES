#include <iostream>
#include "Gen_Ran_Inp.h"
#include "Save_Values.h"

using namespace std;

int main()
{
	Gen_Ran_Inp ran;
	Save_Values save;

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
	return 0;
}
