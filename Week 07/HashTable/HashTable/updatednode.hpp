#ifndef __UPDATEDNODE_HPP__
#define __UPDATEDNODE_HPP__

#include "node.hpp"

class Node01 :public Node
{
public:
	std::string SAYSOMETHING;
};



/*


	Node01 *C = new Node01;
	C->key = "Cherry";
	C->SAYSOMETHING = "This is New";


	Node *Check = table.getNodeByKey("Cherry");
	std::cout << static_cast<Node01*>(Check)->SAYSOMETHING << std::endl;



*/

#endif