//Resources used as reference: https://www.tutorialspoint.com/data_structures_algorithms/tree_data_structure.htm
//https://www.geeksforgeeks.org/insertion-in-a-binary-tree-in-level-order/
#pragma once
#include <iostream>
#include <string>
using namespace std;

struct Node
{
	int value;
	Node *leftChild;
	Node *rightChild;
};

class Binary_Tree
{
public:
	Binary_Tree();
	~Binary_Tree();
	bool insertNode(int value);

private:
	Node *temp;
	Node *current;
	Node *parent;
	Node *root;
};
