#include <iostream>
#include "BianryTree.h"
using namespace std;


int main()
{
	BinaryTree vBinaryTree;
	Node* vNode = new Node;
	
	for (int i = 0; i < 10; i++)
	{
		Node* vNode = new Node;
		vNode->data = i;
		vBinaryTree.InsertNode(vNode);
	}
	return 0;
}