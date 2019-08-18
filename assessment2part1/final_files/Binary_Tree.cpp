#include "Binary_Tree.h"


int Binary_Tree::getMaxHeight(int valA, int valB)
{
	//checks between two integers for the highest value and returns it
	return (valA > valB) ? valA : valB;
}

int Binary_Tree::getHeight(Node * node)
{
	//returns the "height" of a provided node
	//in the case that it does not exist it returns 
	//0
	if (node == nullptr)
		return 0;
	return node->height;
}

Node * Binary_Tree::rootNode(int value)
{
	//this function constructs a node (leaf)
	//that is commonly used to add new data members
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
	//this function checks the balance of the avl tree
	if (node == nullptr)
	{
		return 0;
	}
	else
	{
		//if the discreprency between these two is more than the absolute 
		//value of 2 then rotation is required
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
	//this function returns the node with the tallest height
	//by using a recursive function within itself
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
	//this recursive function prints the value 
	//stored in the nodes at particular levels
	//and also writes to the output file at
	//the same time
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
	//this function is used to print out and write to 
	//an output file as well as the console the avl 
	//tree in the format as shown in the assessment example
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