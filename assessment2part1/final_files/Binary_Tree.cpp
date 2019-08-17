#include "Binary_Tree.h"

Binary_Tree::Binary_Tree()
{
	temp = nullptr;
	current = nullptr;
	parent = nullptr;
	root = nullptr;
}

Binary_Tree::~Binary_Tree()
{
}

bool Binary_Tree::insertNode(int value)
{
	temp->value = value;
	temp->leftChild = nullptr;
	temp->rightChild = nullptr;

	//checks to see that if no tree exists use this first node
	//as the root node
	if (root == nullptr)
	{
		root = temp;
	}
	else
	{
		current = root;
	}

	bool insertSxss = false;

	while (insertSxss)
	{
		parent = current;
		//checking if value is less than parent to go left
		if (value < parent->value)
		{
			current = current->leftChild;
			//inserts the node with the value to the leftchild
			if (current == nullptr)
			{
				parent->leftChild = temp;
				insertSxss = true;
			}
		}
		else
		{
			//checking if value is more than the value in the parent
			//then in this case go to the right
			current = current->rightChild;
			if (current == nullptr)
			{
				parent->rightChild = temp;
				insertSxss = true;
			}
		}
	}
	return true;
}
