
#include "CollisionHandler.h"


	//void CollisionHandler::HandleWallCollision(Camera* lPlayer, QuadTree* lTree) {
	//throw "Not yet implemented";
	//}
CollisionHandler& GetCollisionHandler()
{
	static CollisionHandler mCollisionHandler;
	return mCollisionHandler;
}

bool CollisionHandler::ObjectCollisionCheck(Player* lPlayer, GameObject* lObject) 
{
	D3DXVECTOR3	lObjPos		= lObject->GetPosition();
	D3DXVECTOR3 lPlayerPos	= lPlayer->GetPosition();
	D3DXVECTOR3 TopLeft		=	D3DXVECTOR3(lObjPos.x	- 25, lObjPos.y, lObjPos.z	+ 25);
	D3DXVECTOR3 BotRight	=	D3DXVECTOR3(lObjPos.x	+ 25, lObjPos.y, lObjPos.z	- 25);

	if((lPlayerPos.x < BotRight.x && lPlayerPos.x > TopLeft.x)
	&&(lPlayerPos.z > BotRight.z && lPlayerPos.z < TopLeft.z))
	{
		return true;
	}
	
	return false;
	
}

