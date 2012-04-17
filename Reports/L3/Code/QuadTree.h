#include <exception>
using namespace std;

#ifndef __QuadTree_h__
#define __QuadTree_h__

// #include "WorldHandler.h"
// #include "Node.h"

class WorldHandler;
class Node;
class QuadTree;

class QuadTree
{
	public:
		WorldHandler* worldHandler;
		Node* node;

		Node* GetRootNode();
};

#endif
