#include <vector>
#include "Utilities.h"
#include "ShaderObject.h"
#include "Vertex.h"
//#include "Camera2.h"
#include "Camera.h"
#include "Candy.h"
#include "WallObject.h"
#include "Waypoint.h"
#include "ResourceLoader.h"
using namespace std;

#ifndef WORLDHANDLER_H
#define WORLDHANDLER_H

class WorldHandler
{
public:
		WorldHandler();
		virtual ~WorldHandler();
		void Initialize(ID3D10Device* lDevice);
		void Draw(Camera* lCam);
		Waypoint* GetGhostSpawnWaypoint();

private:
		
		void CreateVertexBuffer( ID3D10Buffer** lVB, int lSize  );
		void SetResources();
		void SetupVertices();
		void CreateLevel();
		void LoadWaypoints();

private:
		ID3D10Device* mDevice;
		ShaderObject* mShaderObject;

		D3DXMATRIX mWorldMatrix;
		D3DXMATRIX mViewProjMatrix;
		ID3D10Buffer* mVertexBuffer;

		vector<WallObject*> mWallObject;
		vector<Candy*> mCandy;
		vector<Waypoint*> mWaypoint;


};

#endif
