#include <iostream>
#include <list>
#include "Node_ACMCraft.h"
using namespace std;

Node::Node()
{
	value = 0;
	nextnode.clear();
	isHead = true;
}

void Node::setNextNode(Node tmp) { nextnode.push_back(tmp); }

int Node::getCount() { return nextnode.size(); }

Node Node::getNextNode() { return nextnode.front(); }