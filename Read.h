#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Read
{
public:
	Read();
	~Read();
	void readMyFile(string fileName);
private:

};

Read::Read()
{
}

Read::~Read()
{
}

void Read::readMyFile(string fileName)
{
	string line;
	ifstream myfile(fileName);
	if (myfile.is_open())
	{
		while (!myfile.eof())
		{
			getline(myfile, line);
			cout << line << "\n";
		}
	}
	else
	{
		cout << "Error: File Open for read";
	}
}