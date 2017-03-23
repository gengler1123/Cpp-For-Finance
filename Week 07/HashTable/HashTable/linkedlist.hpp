#ifndef __LINKEDLIST_HPP__
#define __LINKEDLIST_HPP__

#include "node.hpp"
#include <iostream>

#include <string>

class LinkedList
{
private:
	int length = 0;
public:
	Node *first;
	Node *end;
	LinkedList()
	{
		first = NULL;
		end = NULL;
		length = 0;
	}
	~LinkedList();


	void addNodeBegin(Node *node_)
	{
		if (first == NULL)
		{
			std::cout << "HERE" << std::endl;
			first = node_;
			end = node_;
		}
		else
		{
			std::cout << "ELSE" << std::endl;
			node_->next = first->next;
			first = node_;
		}
		length++;
	}

	int getLength()
	{
		return length;
	}

	void addNodeEnd(Node *node_);

	Node *searchList(std::string key_);

	bool deleteNode(std::string key_);

};



void LinkedList::addNodeEnd(Node *node_)
{
	if (end == NULL)
	{
		first = node_;
		end = node_;
	}
	else
	{
		end->next = node_;
		end = node_;
	}
	length++;
}



Node* LinkedList::searchList(std::string key_)
{
	Node *current = first;
	while (current)
	{
		if (current->key == key_)
		{
			return current;
		}
		current = current->next;
	}
	return NULL;
}


bool LinkedList::deleteNode(std::string key_)
{
	if (!first->next) return false;
	Node *p = first;
	Node *q = first;

	while (q)
	{
		if (q->key == key_)
		{
			p->next = q->next;
			delete q;
			length--;
			return true;
		}
		p = q;
		q = p->next;
	}
	return false;
}





LinkedList::~LinkedList()
{
	Node * p = first;
	Node * q = first;
	while (q)
	{
		p = q;
		q = p->next;
		delete p;
	}
}

#endif