#pragma once
#include <iostream>
using namespace std;

typedef struct Node
{
	Node()
	{
		data = 0;
		right = nullptr;
		left = nullptr;
	}
	int data;
	Node* right;
	Node* left;
};

class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();
	//Insert the data into the binary tree
	bool InsertNode(Node*);
	//BFS search
	int TraverseBFS();
	//DFS search
	int TraverseDFS();
private:
	Node* root;
	Node* getEmpty(Node*);
};

BinaryTree::BinaryTree()
{
	root = new Node();
}

BinaryTree::~BinaryTree()
{
	delete root;
}

bool BinaryTree::InsertNode(Node* pNode)
{
	//if root node is empty we can set pnode to root node
	if (root == nullptr)
	{
		root = pNode;
	}
	//otherwise we need to find an empty node
	else
	{
		//we forward the root node to find the empty node
		Node* vNode = getEmpty(root);
		vNode = pNode;
	}
	return true;
}

Node* BinaryTree::getEmpty(Node* pNode)
{
	//check if the left of the node is empty
	//create an empty node and return the reference
	if (pNode->left == nullptr)
	{
		pNode->left = new Node;
		return pNode->left;
	}
	else
	{
		getEmpty(pNode->left);
	}
	//check if the right of the node is empty
	//create an empty node and return the reference
	if (pNode->right == nullptr)
	{
		pNode->right = new Node;
		return pNode->right;
	}
	else
	{
		getEmpty(pNode->right);
	}

	//code should never reach here
	return nullptr;
}