#include <iostream>
#include <string>
#include "Gen_Ran_Inp.h"
#include "Save_Values.h"
using namespace std;

int main()
{
	int sortOrder = -2;
	int complexity = -2;
	int numOfItems = -2;
	int *items;
	//Gen_Ran_Inp random;
	//random.writeRanInput();
	
	Save_Values save;
	items = save.saveFromInput(&sortOrder, &complexity, &numOfItems);

	cout << sortOrder << endl;
	cout << complexity << endl;
	cout << numOfItems << endl;
	for (int i = 0; i < numOfItems; i++)
	{
		if (i == (numOfItems - 1))
		{
			cout << items[i];
		}
		else
		{
			cout << items[i] << " ";
		}
	}
	cout << endl;
	return 0;
}
