#include <iostream>
#include "LinkedList.h"
#include "NumberGen.h"
#include "SaveNumber.h"

using namespace std;

int main()
{
	int numberOfItems = 0;
	NumberGen gen;
	gen.writeRanInp();
	SaveNumber save;
	save.saveSize(&numberOfItems);
	cout << numberOfItems << endl;
	LinkedList lList;
	//lList.insertAtEnd(numberOfItems);
	lList.displayNodes();
	return 0;
}