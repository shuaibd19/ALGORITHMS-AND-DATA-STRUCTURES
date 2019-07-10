#include <iostream>
#include "Read.h"
#include "Write.h"
#include <string>

using namespace std;

int main()
{
	//string iFileName = "input-a1q1.txt";
	//keep this to the minimum
	string oFileName = "output-a1q1.txt";
	Read read;
	Write write;
	write.writeToFile(oFileName);
	read.readMyFile(oFileName);
	return 0;
}
