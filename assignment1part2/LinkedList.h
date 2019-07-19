#pragma once
#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
};

class LinkedList
{
public:
	LinkedList();
	~LinkedList();
	void insertAtBeginning(int numOfElm);
	void deleteFromBeginning();
	void insertAtEnd(int numOfElm);
	void deleteFromEnd();
	void displayNodes();

private:
	Node *First;
	Node *Last;
	Node *Current;
};

LinkedList::LinkedList()
{
	First = NULL;
	Last = NULL;
	Current = NULL;

}

LinkedList::~LinkedList()
{
}

void LinkedList::insertAtBeginning(int numOfElm)
{

}

void LinkedList::deleteFromBeginning()
{
	
}

void LinkedList::insertAtEnd(int numOfElm)
{
	//creating a new 'temp' node with the provided value going to 
	//its data member. The node is being added to the end hence 
	//it pointing to NULL
	Node *temp = new Node;
	temp->data = numOfElm;
	temp->next = NULL;

	if (First == NULL)
	{
		//This piece of code makes sure the linked list is not empty - 
		//if the first node is null then this is the case -
		//in such a case the first node is both the first and the last
		//item on the linked list
		First = temp;
		Last = temp;
	}
	else
	{
		//In the case where there already is a node this makes that node 
		//(known as 'Last') point to the new temp Node and makes the 
		//temp node now the 'Last' node. Therefore inserting at end
		Last->next = temp;
		Last = Last->next;
	}
}

void LinkedList::deleteFromEnd()
{
	
}

void LinkedList::displayNodes()
{
	Node *temp = new Node;
	temp = First;
	while (temp != NULL)
	{
		cout << temp->data << ", ";
		temp = temp->next;
	}
}