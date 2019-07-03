#include <iostream>
#include <time.h>
#include "Box.h"

using namespace std;



int main()
{
	Box box1; //decalaration of a box1 of type BOX
	Box box2; //decalaration of a box2 of type BOX
	double volume1 = 0.0; // Store the volume of the box here
	double volume2 = 0.0;

	//box1 specs
	box1.setLength(12.0);
	box1.setHeight(10.0);
	box1.setBreadth(5.0);

	//box2 specs
	box2.setLength(10.0);
	box2.setHeight(12.0);
	box2.setBreadth(6.5);

	volume1 = box1.calcVolume();
	volume2 = box2.calcVolume();

	cout << "box1 has the volume of: " << volume1 << "cubic" << endl;
	cout << "box2 has the volume of: " << volume2 << "cubic" << endl;
	return 0;
}

