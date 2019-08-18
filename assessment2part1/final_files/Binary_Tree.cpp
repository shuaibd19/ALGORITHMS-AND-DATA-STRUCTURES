#include "Binary_Tree.h"


int Binary_Tree::getMaxHeight(int valA, int valB)
{
	return (valA > valB) ? valA : valB;
}

int Binary_Tree::getHeight(Node * node)
{
	if (node == nullptr)
		return 0;
	return node->height;
}

Node * Binary_Tree::rootNode(int value)
{
	Node *root = new Node;
	root->value = value;
	root->leftChild = nullptr;
	root->rightChild = nullptr;
	root->height = 1;

	return root;
}


Node * Binary_Tree::rotateRight(Node * y)
{
	Node *x = y->leftChild;
	Node *w = y->rightChild;

	//rotate
	x->rightChild = y;
	y->leftChild = w;

	//update heights
	y->height = getMaxHeight(getHeight(y->leftChild), getHeight(y->rightChild)) + 1;
	x->height = getMaxHeight(getHeight(x->leftChild), getHeight(x->rightChild)) + 1;

	return x;
}

Node * Binary_Tree::rotateLeft(Node * x)
{
	Node *y = x->rightChild;
	Node *w = y->leftChild;

	//rotate
	y->leftChild = x;
	x->rightChild = w;

	//update heights
	x->height = getMaxHeight(getHeight(x->leftChild), getHeight(x->rightChild)) + 1;
	y->height = getMaxHeight(getHeight(y->leftChild), getHeight(y->rightChild)) + 1;

	return y;
}

int Binary_Tree::balance(Node * node)
{
	if (node == nullptr)
	{
		return 0;
	}
	else
	{
		return getHeight(node->leftChild) - getHeight(node->rightChild);
	}
}




Node * Binary_Tree::insertNode(Node * node, int value)
{
	int treeBalance = 0;

	//checks to see that if no tree exists use this first node
	//as the root node
	if (node == nullptr)
	{
		node = rootNode(value);
		return node;
	}

	//by using recursive function it keeps on going through
	//the binary tree until it can be eligable to add a leaf node
	if (value < node->value)
	{
		node->leftChild = insertNode(node->leftChild, value);
	}
	else if (value > node->value)
	{
		node->rightChild = insertNode(node->rightChild, value);
	}
	else
	{
		return node;
	}

	node->height = getMaxHeight(getHeight(node->leftChild), getHeight(node->rightChild)) + 1;
	treeBalance = balance(node);

	//whenever the tree balance value has a difference of greater than
	//1 then rotation must occur accordingly with the AVL tree rules

	//LL 
	if (treeBalance > 1 && value < node->leftChild->value)
	{
		return rotateRight(node);
	}

	//RR
	if (treeBalance < -1 && value > node->rightChild->value)
		return rotateLeft(node);

	//LR  
	if (treeBalance > 1 && value > node->leftChild->value)
	{
		node->leftChild = rotateLeft(node->leftChild);
		return rotateRight(node);
	}

	//RL
	if (treeBalance < -1 && value < node->rightChild->value)
	{
		node->rightChild = rotateRight(node->rightChild);
		return rotateLeft(node);
	}

	return node;

}

int Binary_Tree::tallestHeight(Node * node)
{
	if (node == nullptr)
	{
		return 0;
	}
	else
	{
		int leftH = tallestHeight(node->leftChild);
		int rightH = tallestHeight(node->rightChild);

		if (leftH > rightH)
		{
			return(leftH + 1);
		}
		else
		{
			return(rightH + 1);
		}
		
	}
}

void Binary_Tree::printNodeLevel(Node * node, int level)
{
	if (node == nullptr)
	{
		return;
	}
	if (level == 1)
	{
		
		cout << node->value << " ";
		myFile << node->value << " ";
	}
	else if (level > 1)
	{
		printNodeLevel(node->leftChild, level - 1);
		printNodeLevel(node->rightChild, level - 1);
	}
}

void Binary_Tree::printBFS(Node * node)
{
	myFile.open("output-q1-a2.txt");
	int h = tallestHeight(node);
	for (int i = 1; i <= h; i++)
	{
		cout << i - 1 << ": ";
		myFile << i - 1 << ": ";
		printNodeLevel(node, i);
		cout << endl;
		myFile << "\n";
	}
	myFile.close();
}

Binary_Tree::Binary_Tree()
{
}

Binary_Tree::~Binary_Tree()
{
}