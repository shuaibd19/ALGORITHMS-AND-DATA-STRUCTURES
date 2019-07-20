/*references: https://www.codementor.io/codementorteam/a-comprehensive-guide-to-implementation-of-singly-linked-list-using-c_plus_plus-ondlm5azr
https://www.geeksforgeeks.org/remove-last-node-of-the-linked-list/
https://www.codesdope.com/blog/article/c-linked-lists-in-c-singly-linked-list/ 
https://codeforwin.org/2015/09/c-program-to-delete-last-node-of-singly-linked-list.html 
https://www.youtube.com/watch?time_continue=252&v=i3b3O7slIzk */

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
	//Function to insert node at beginning of my linked list
	void insertAtBeginning(int num);
	//Function to delete node at beginning of my linked list
	void deleteFromBeginning();
	//Function to insert node at end of my linked list
	void insertAtEnd(int num);
	//void deleteFromEnd();
	//Function used to loop through linkedlist display all nodes
	void displayNodes();

private:
	//Also known as head or tail nodes in Linked List terminology
	Node *First;
	Node *Last;
};

LinkedList::LinkedList()
{
	//Making sure they are not fed garbage values during compilation
	First = NULL;
	Last = NULL;
}

LinkedList::~LinkedList()
{
}

void LinkedList::insertAtBeginning(int num)
{
	//Using dynamic memory allocation to assign new Node temp and put int num
	//inside its data member
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
		//Making the temp point to the first and thus making it the first
		//node
		temp->next = First;
		First = temp;
	}
}

void LinkedList::deleteFromBeginning()
{
	//If the first node is NUll then it's already empty so don't
	//do anything
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
//void LinkedList::deleteFromEnd()
//{
//	Node *Current = new Node;
//	Node *Previous = new Node;
//
//	if (First == NULL)
//	{
//
//	}
//	else
//	{
//		if (First->next == NULL)
//		{
//			Current = First;
//			First = NULL;
//			free(Current);
//		}
//		else
//		{
//			Current = First;
//			while (Current->next != NULL)
//			{
//				Previous = Current;
//				Current = Current->next;
//			}
//			Previous->next = NULL;
//			free(Current);
//		}
//	}
//}

void LinkedList::displayNodes()
{
	//create a Node the will traverse through the linked list
	//until reaching the  final node printing all the data members
	//in the process and moving on to the next
	Node *temp = new Node;
	temp = First;
	while (temp != NULL)
	{
		cout << temp->data << ", ";
		temp = temp->next;
	}
}
