#include "Candy.h"


Candy::Candy( int lType ,D3DXVECTOR3 lPosition )
	: GameObject()
{
	//Default Contructor
	mPosition = lPosition;
	mType = lType;
}

Candy::~Candy()
{

}


void Candy::SetResources()
{
	D3DXMatrixIdentity(&mWorldMatrix);
	D3DXMatrixTranslation(&mWorldMatrix, mPosition.x, mPosition.y, mPosition.z);

}