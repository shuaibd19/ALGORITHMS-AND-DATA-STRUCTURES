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
	myfile << "0\n1\n5\n56 12 1 4 9" << endl;
	myfile.close();
}
