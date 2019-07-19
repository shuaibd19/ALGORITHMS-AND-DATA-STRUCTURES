#pragma once

struct Node
{
	int data;
	Node *next;
};

class SlinkedList
{
public:
	SlinkedList();
	~SlinkedList();

	bool insertAtBeginning();
	bool deleteFromBeginning();
	bool insertAtEnd();
	bool deleteFromEnd();

private:
	Node *First;
	Node *Last;
	Node *Current;
};

SlinkedList::SlinkedList()
{
}

SlinkedList::~SlinkedList()
{
}

bool SlinkedList::insertAtBeginning()
{
}

bool SlinkedList::deleteFromBeginning()
{
}

bool SlinkedList::insertAtEnd()
{
}

bool SlinkedList::deleteFromEnd()
{
}
