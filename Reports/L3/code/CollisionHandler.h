#ifndef COLLISIONHANDLER_H
#define COLLISIONHANDLER_H


// #include "GameScreen.h"
#include "Camera.h"
#include "GameObject.h"
#include "Player.h"
// #include "QuadTree.h"


class CollisionHandler
{
	public:

		//void HandleWallCollision(Camera* lPlayer, QuadTree* lTree);
		bool ObjectCollisionCheck(Player* lPlayer, GameObject* lObject);
};
CollisionHandler& GetCollisionHandler();

#endif
