
#ifndef __Node_h__
#define __Node_h__

// #include "QuadTree.h"

class QuadTree;
class Node;

class Node
{
	public:
		QuadTree* quadTree;

	private:
		Node mAdjecent[];
		WallObject mWallObjects[];

};

#endif
