#pragma once

//using namespace std;

class Box {
public:
	double length; //length of the box
	double breadth; //breadth of the box
	double height; //height of the box

	double calcVolume();
	void setLength(double l);
	void setBreadth(double b);
	void setHeight(double h);
};

//Member functions definitions

double Box::calcVolume(void)
{
	return length * breadth * height;
}

void Box::setLength(double l)
{
	length = l;
}

void Box::setBreadth(double b)
{
	breadth = b;
}

void Box::setHeight(double h)
{
	height = h;
}
