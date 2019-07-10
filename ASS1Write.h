#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Write
{
public:
	Write();
	~Write();
	void writeToFile(string fileName);
private:

};

Write::Write()
{
}

Write::~Write()
{
}

void Write::writeToFile(string fileName)
{
	ofstream myfile;
	myfile.open(fileName);
	myfile << 0 << endl;
	myfile << 1 << endl;
	myfile << 10 << endl;
	myfile << 1 << " " << 2 << " " << 3 << " " << 4 << " " << 5 <<
		" " << 6 << " " << 7 << " " << 8 << " " << 9 << " " << 10;
	myfile.close();
}
