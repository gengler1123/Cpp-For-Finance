#ifndef __TABLEHASH_HPP__
#define __TABLEHASH_HPP__

#include "LinkedList.hpp"
#include <iostream>


class HashTable
{
private:
	LinkedList *LL;
	unsigned int length;
public:
	HashTable(unsigned int length_ = 13)
	{
		length = length_;
		LL = new LinkedList[length];
	};

	~HashTable()
	{
		delete[] LL;
	};

	int hash(std::string key_)
	{
		int value = 0;
		for (int i = 0; i < key_.length(); i++)
		{
			value += key_[i];
		}
		return (value * key_.length()) % length;
	};

	void insertNode(Node *node_)
	{
		int idx = hash(node_->key);
		LL[idx].addNodeEnd(node_);
	};

	bool removeNode(std::string key_)
	{
		int idx = hash(key_);
		return LL[idx].deleteNode(key_);
	};


	Node * getNodeByKey(std::string key_)
	{
		int idx = hash(key_);
		return LL[idx].searchList(key_);
	};

	void printHistogram()
	{
		std::cout << "\n\nHash Table Contains ";
		std::cout << getNumberOfItems() << " Items total\n";
		for (int i = 0; i < length; i++)
		{
			std::cout << i + 1 << ":\t";
			for (int j = 0; j < LL[i].getLength(); j++)
				std::cout << " X";
			std::cout << "\n";
		}
	}


	int getNumberOfItems()
	{
		int itemCount = 0;
		for (int i = 0; i < length; i++)
		{
			itemCount += LL[i].getLength();
		}
		return itemCount;
	}

};






#endif