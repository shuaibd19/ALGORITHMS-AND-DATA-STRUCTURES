//Resources used as reference: https://www.tutorialspoint.com/data_structures_algorithms/tree_data_structure.htm
//https://www.geeksforgeeks.org/insertion-in-a-binary-tree-in-level-order/
//https://www.geeksforgeeks.org/level-order-tree-traversal/
//https://www.geeksforgeeks.org/avl-tree-set-1-insertion/
#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Node
{
	int value;
	int height;
	Node *leftChild;
	Node *rightChild;
};

class Binary_Tree
{
public:
	Node * rootNode(int value);
	Node * insertNode(Node *node, int value);
	//used to get the maximum of two values
	int getMaxHeight(int valA, int valB);
	//Used to get the height of the avl tree
	int getHeight(Node *node);
	//rotate subtree to the right
	Node *rotateRight(Node *y);
	//rotate subtree to the left
	Node *rotateLeft(Node *x);
	//Return the balance value
	int balance(Node *node);
	int tallestHeight(Node *node);
	void printNodeLevel(Node *node, int level);
	void printBFS(Node *node);
	Binary_Tree();
	~Binary_Tree();

	ofstream myFile;
};
