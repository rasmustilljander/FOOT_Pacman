#include <exception>
#include <vector>
#include "Utilities.h"
#include "ShaderObject.h"
#include "Vertex.h"
#include "Camera.h"
#include "Candy.h"
#include "WallObject.h"
#include "ResourceLoader.h"
using namespace std;

#ifndef __WorldHandler_h__
#define __WorldHandler_h__


// #include "QuadTree.h"
// #include "Waypoints.h"
// #include "WallObject.h"

class WorldHandler
{
public:
		WorldHandler();
		virtual ~WorldHandler();

		void Initialize(ID3D10Device* lDevice);
		void Draw( Camera* lCam );
private:
		
		void CreateVertexBuffer( ID3D10Buffer** lVB, int lSize  );
		void SetResources();
		void SetupVertices();

		void CreateLevel();


private:
		ID3D10Device* mDevice;
		ShaderObject* mShaderObject;

		D3DXMATRIX mWorldMatrix;
		D3DXMATRIX mViewProjMatrix;
		ID3D10Buffer* mVertexBuffer;

		//Waypoint mWaypoint[];
		//QuadTree* quadTree;
		//Waypoints* waypoints;
		vector<WallObject*> mWallObject;
		vector<Candy*> mCandy;

};

#endif
