#include <iostream>
#include "Read.h"
#include "Ran_Write.h"
#include <string>

using namespace std;

int main()
{
	string iFileName = "input-a1q1.txt";
	//keep this to the minimum
	//string oFileName = "output-a1q1.txt";
	Read read;
	Ran_Write write;
	write.writeToFile(iFileName);
	read.readMyFile(iFileName);
	return 0;
}
