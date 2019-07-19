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
	void insertAtBeginning(int num);
	void deleteFromBeginning();
	void insertAtEnd(int num);
	void deleteFromEnd();
	void displayNodes();

private:
	Node *First;
	Node *Last;
};

LinkedList::LinkedList()
{
	First = NULL;
	Last = NULL;
}

LinkedList::~LinkedList()
{
}

void LinkedList::insertAtBeginning(int num)
{
	Node *temp = new Node;
	temp->data = num;
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
		temp->next = First;
		First = temp;
	}
}

void LinkedList::deleteFromBeginning()
{
	if (First == NULL)
	{

	}
	else
	{
		Node *temp = new Node;
		//Store the first node in temporary node
		temp = First;
		//The new first node is the one after the original
		First = First->next;
		//delete the temp node and hence the first node
		delete temp;
	}

}

void LinkedList::insertAtEnd(int num)
{
	//creating a new 'temp' node with the provided value going to 
	//its data member. The node is being added to the end hence 
	//it pointing to NULL
	Node *temp = new Node;
	temp->data = num;
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

//this node is problematic and crashing my program!!!!
void LinkedList::deleteFromEnd()
{
	Node *Current = new Node;
	Node *Previous = new Node;
	Current = First;
	while (Current->next != NULL)
	{
		Previous = Current;
		Current = Current->next;
	}
	Last = Previous;
	Previous->next = NULL;
	delete Current;
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
