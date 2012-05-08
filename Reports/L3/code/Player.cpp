#include "Player.h"

Player::Player()
	: NonStaticGameObject()
{
	mOldPosition = D3DXVECTOR3(0,0,0);
	mPosition	 = D3DXVECTOR3(0,0,0);
}

Player::~Player()
{

}

void Player::Update(float lDT)
{

}

void Player::SetResources()
{
	mShaderObject->SetResource("tex2D", GetResourceLoader().Get2DPacmanTeture());
}

void Player::SetupVertices()
{
	BillboardVertex* data = NULL;

	mVertexBuffer->Map( D3D10_MAP_WRITE_DISCARD, 0, reinterpret_cast< void** > ((void**)&data) );

	//data[0].centerW = mPosition;
	//data[0].sizeW = D3DXVECTOR2(50, 50);

	mVertexBuffer->Unmap();
}

void Player::SetPosition(D3DXVECTOR3 lPos)
{
	mOldPosition = mPosition;
	mPosition = lPos;
}