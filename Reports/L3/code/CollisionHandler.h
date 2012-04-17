#include <exception>
using namespace std;

#ifndef __CollisionHandler_h__
#define __CollisionHandler_h__

// #include "GameScreen.h"
// #include "Camera.h"
// #include "QuadTree.h"

class GameScreen;
class Camera;
class QuadTree;
class CollisionHandler;

class CollisionHandler
{
	public:
		GameScreen* gameScreen;

		void HandleWallCollision(Camera* lPlayer, QuadTree* lTree);
		bool AABBCollisionCheck(Camera* lPlayer, GameObject* lObject);
};

#endif
