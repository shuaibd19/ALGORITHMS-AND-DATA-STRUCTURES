#pragma once
#include <iostream>
#include <time.h>
#include <fstream>
#include <math.h>
using namespace std;

class NumberGen
{
public:
	NumberGen();
	~NumberGen();
	void writeRanInp();

private:
	long long int randomNumber;
};

NumberGen::NumberGen()
{
	/*due to rand function having a max value i have to to do something smart*/
	srand((unsigned)time(NULL));
	randomNumber = (int)pow((double)(rand() % 999999), 1.3);
}

NumberGen::~NumberGen()
{
}

void NumberGen::writeRanInp()
{
	ofstream myFile;
	myFile.open("input-a1q2.txt");
	myFile << randomNumber << endl;
	myFile.close();
}
