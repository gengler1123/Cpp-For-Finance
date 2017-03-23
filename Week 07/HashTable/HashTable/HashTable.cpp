// HashTable.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "linkedlist.hpp"
#include "tableHash.hpp"
#include "updatednode.hpp"

int _tmain(int argc, _TCHAR* argv[])
{

	Node *A = new Node;
	A->key = "Apple";
	Node *B = new Node;
	B->key = "Bannana";

	HashTable table;
	table.insertNode(A);
	table.insertNode(B);
	table.insertNode(C);
	table.printHistogram();



	return 0;
}

