#include <exception>
using namespace std;

#ifndef __NonStaticGameObject_h__
#define __NonStaticGameObject_h__

#include "GameObject.h"

// class GameObject;
class NonStaticGameObject;

__abstract class NonStaticGameObject: public GameObject
{
	public:

		void Update(float dt);
};

#endif
