#include <exception>
using namespace std;

#ifndef __Ghost_h__
#define __Ghost_h__

#include "NonStaticGameObject.h"

// class NonStaticGameObject;
class Ghost;

class Ghost: public NonStaticGameObject
{
	public:

		void Move(float dt);
		void SetTargetPosition(D3DXVECTOR lTargetPosition);
};

#endif
