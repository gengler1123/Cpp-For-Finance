// linkedList.cpp : Defines the entry point for the console application.
//

#include <iostream>


class Node
{
public:
	int value;
	Node *next = NULL;
};


class LinkedList
{
public:
	Node *first = NULL;
	Node *end = NULL;
	void addNodeBegin(int value_)
	{
		Node *n = new Node;
		n->value = value_;
		if (first == NULL)
		{
			first = n;
			end = n;
		}
		else
		{
			n->next = first;
			first = n;
		}
	}
	void addNodeEnd(int value_);

	Node *searchList(int value_);

	bool deleteNode(int value_);

};


void LinkedList::addNodeEnd(int value_)
{
	Node *n = new Node;
	n->value = value_;
	if (end == NULL)
	{
		first = n;
		end = n;
	}
	else
	{
		end->next = n;
		end = n;
	}
}


Node* LinkedList::searchList(int value_)
{
	Node *current = first;
	while (current)
	{
		if (current->value == value_)
		{
			return current;
		}
		current = current->next;
	}
	return NULL;
}


bool LinkedList::deleteNode(int value_)
{
	Node *a = first;
	Node *b = first;

	if (first->value == value_)
	{
		a = first->next;
		if (a == NULL)
		{
			end = a;
		}
		delete[] first;
		first = a;
		return true;
	}

	while (a->next)
	{

		b = a->next;

		if (b->value == value_)
		{
			
			a->next = b->next;
			if (b == end)
			{
				end = a;
			}
			delete[] b;
			return true;
		}

		a = a->next;

	}
	return false;
}


int main()
{



	return 0;
}