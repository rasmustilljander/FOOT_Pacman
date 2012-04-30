#ifndef NONSTATICGAMEOBJECT_H
#define NONSTATICGAMEOBJECT_H

#include "GameObject.h"


class NonStaticGameObject: public GameObject
{
public:
	NonStaticGameObject();
	virtual ~NonStaticGameObject();

	virtual void Update(float lDT) = 0;


};

#endif
