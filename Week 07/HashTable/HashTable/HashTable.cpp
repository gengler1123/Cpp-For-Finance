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

	Node01 *C = new Node01;
	C->key = "Cherry";
	C->SAYSOMETHING = "This is New";



	HashTable table;
	table.insertNode(A);
	table.insertNode(B);
	table.insertNode(C);
	table.printHistogram();



	Node *Check = table.getNodeByKey("Cherry");

	std::cout << Check->key << std::endl;

	std::cout << static_cast<Node01*>(Check)->SAYSOMETHING << std::endl;


	return 0;
}

