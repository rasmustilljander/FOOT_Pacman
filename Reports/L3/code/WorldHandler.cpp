#include "WorldHandler.h"

WorldHandler::WorldHandler()
{
	mShaderObject = new ShaderObject();
}

WorldHandler::~WorldHandler()
{
	delete mShaderObject;
	//SAFE_RELEASE(mVertexBuffer);
	mWallObject.clear();
	mCandy.clear();
	mWaypoint.clear();
}

void WorldHandler::Initialize(ID3D10Device* lDevice) 
{
	mDevice = lDevice;

	mShaderObject->Initialize( mDevice, "wall.fx", VertexLayout, vertexInputLayoutNumElements, "drawTech", D3D10_SHADER_ENABLE_BACKWARDS_COMPATIBILITY );
	CreateVertexBuffer( &mVertexBuffer, 4 );
	SetResources();
	SetupVertices();
	LoadWaypoints();
	CreateLevel();

	for(UINT i = 0; i < mCandy.size(); i++)
	mCandy.at(i)->Initialize(mDevice, "gameobject.fx");


	for(UINT i = 0; i < mWallObject.size(); i++)
		mWallObject.at(i)->Initialize(lDevice);
}

void WorldHandler::CreateVertexBuffer( ID3D10Buffer** lVB, int lSize  )
{
	D3D10_BUFFER_DESC bd;
	bd.Usage = D3D10_USAGE_DYNAMIC;
	bd.ByteWidth = sizeof( Vertex ) * lSize;
	bd.BindFlags = D3D10_BIND_VERTEX_BUFFER;
	bd.CPUAccessFlags = D3D10_CPU_ACCESS_WRITE;
	bd.MiscFlags = 0;

	mDevice->CreateBuffer( &bd, 0, lVB );
}

void WorldHandler::SetResources()
{
	D3DXMatrixIdentity(&mWorldMatrix);
	//D3DXMatrixTranslation(&mWorldMatrix, -0.5f, 0, 0);
	mShaderObject->SetMatrix("worldMatrix", mWorldMatrix);
	mShaderObject->SetResource("tex2D", GetResourceLoader().GetWallTexture());
}

void WorldHandler::SetupVertices()
{
	Vertex* data = NULL;

	mVertexBuffer->Map( D3D10_MAP_WRITE_DISCARD, 0, reinterpret_cast< void** > ((void**)&data) );

	data[0].pos = D3DXVECTOR3(0,0,0);
	data[0].texC = D3DXVECTOR2(0,0);
	data[0].normal = D3DXVECTOR3(0,1,0);

	data[1].pos = D3DXVECTOR3(1000,0,0);
	data[1].texC = D3DXVECTOR2(1,0);
	data[1].normal = D3DXVECTOR3(0,1,0);

	data[2].pos = D3DXVECTOR3(0,0,1000);
	data[2].texC = D3DXVECTOR2(0,1);
	data[2].normal = D3DXVECTOR3(0,1,0);

	data[3].pos = D3DXVECTOR3(1000,0,1000);
	data[3].texC = D3DXVECTOR2(1,1);
	data[3].normal = D3DXVECTOR3(0,1,0);

	mVertexBuffer->Unmap();
}

void WorldHandler::CreateLevel()
{
	//SideWalls
	mWallObject.push_back(new WallObject(D3DXVECTOR3(250,25,0), 500, 50, D3DXVECTOR3(0,0,1)));
	mWallObject.push_back(new WallObject(D3DXVECTOR3(250,25,500), 500, 50, D3DXVECTOR3(0,0,-1)));
	mWallObject.push_back(new WallObject(D3DXVECTOR3(0,25,250), 500, 50, D3DXVECTOR3(1,0,0)));
	mWallObject.push_back(new WallObject(D3DXVECTOR3(500,25,250), 500, 50, D3DXVECTOR3(-1,0,0)));

	//
	mWallObject.push_back(new WallObject(D3DXVECTOR3(50,25,120), 140, 50, D3DXVECTOR3(1,0,0)));
	
	mWallObject.push_back(new WallObject(D3DXVECTOR3(120,25,50), 140, 50, D3DXVECTOR3(0,0,-1)));
	mWallObject.push_back(new WallObject(D3DXVECTOR3(70,25,310), 140, 50, D3DXVECTOR3(0,0,-1)));

	mCandy.push_back(new Candy(1,D3DXVECTOR3(2000,0,0)));
	mCandy.push_back(new Candy(1, D3DXVECTOR3(400,25,400)));
	mCandy.push_back(new Candy(0, D3DXVECTOR3(50,25,50)));
	mCandy.push_back(new Candy(0, D3DXVECTOR3(200,25,50)));
}
void WorldHandler::LoadWaypoints()
{
	mWaypoint.push_back(new Waypoint(D3DXVECTOR3(0, 50, 50))); //0
	mWaypoint.push_back(new Waypoint(D3DXVECTOR3(50, 50, 50))); //1
	mWaypoint.push_back(new Waypoint(D3DXVECTOR3(50, 50, 500))); //2
	mWaypoint.push_back(new Waypoint(D3DXVECTOR3(500, 50, 500))); //3	
	mWaypoint.push_back(new Waypoint(D3DXVECTOR3(500, 50, 50))); //4

	// när du länkar waypoints tänk på att antingen x eller z värdet måste vara lika på de 2 hopplänkade, annars får spökena fnatt

	mWaypoint.at(0)->AddAdjecentWaypoint(mWaypoint.at(1)); //Test Spawn
	//1 50 50 50
	mWaypoint.at(1)->AddAdjecentWaypoint(mWaypoint.at(2)); //50 50 50	-- 50 50 300  // går
	mWaypoint.at(1)->AddAdjecentWaypoint(mWaypoint.at(4)); //50 50 50	--  300 50 50	// lol går
	//2 50 50 300
	mWaypoint.at(2)->AddAdjecentWaypoint(mWaypoint.at(1)); //50 50 300 --  50 50 50	//går
	mWaypoint.at(2)->AddAdjecentWaypoint(mWaypoint.at(3));//50 50 300 --  300 50 300	// går
	//3 300 50 50
	mWaypoint.at(3)->AddAdjecentWaypoint(mWaypoint.at(2));  //300 50 50			50 50 300	// lol gg
	mWaypoint.at(3)->AddAdjecentWaypoint(mWaypoint.at(4));	//300 50 50			300 50 50	//går
	//4 300 50 300
	mWaypoint.at(4)->AddAdjecentWaypoint(mWaypoint.at(3)); //300 50 300			300 50 50	//går
	mWaypoint.at(4)->AddAdjecentWaypoint(mWaypoint.at(1)); //300 50 300			 50 50 50	//nej	


}

void WorldHandler::Draw( Camera2* lCam )
{
	mShaderObject->SetMatrix("viewMatrix", lCam->getViewMatrix());
	mShaderObject->SetMatrix("projMatrix", lCam->getProjectionMatrix());

	/*mShaderObject->SetMatrix("viewMatrix", lCam->GetView());
	mShaderObject->SetMatrix("projMatrix", lCam->GetProjection());*/
	mDevice->IASetPrimitiveTopology(D3D10_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);
	UINT stride = sizeof(Vertex);
	UINT offset = 0;

	mDevice->IASetVertexBuffers(0,1, &mVertexBuffer, &stride, &offset);

	D3D10_TECHNIQUE_DESC techDesc;
	mShaderObject->GetTechnique()->GetDesc( &techDesc );

	for( UINT p = 0; p < techDesc.Passes; p++ )
	{
		mShaderObject->Render(p);
		mDevice->Draw(4,0);
	}
	for(UINT i = 0; i < mWallObject.size(); i++)
	{
		mWallObject.at(i)->Draw(lCam);
	}
	for(UINT i = 0; i < mCandy.size(); i++)
	{
	mCandy.at(i)->Draw( lCam );
	}
}

Waypoint* WorldHandler::GetGhostSpawnWaypoint()
{
	return mWaypoint.at(0);
}