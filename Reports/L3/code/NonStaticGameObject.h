#ifndef NONSTATICGAMEOBJECT_H
#define NONSTATICGAMEOBJECT_H

#include "GameObject.h"


class NonStaticGameObject: public GameObject
{
public:
	NonStaticGameObject();
	virtual ~NonStaticGameObject();

	void Update(float dt) = 0;


};

#endif
