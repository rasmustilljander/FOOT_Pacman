#include <exception>
#include "Utilities.h"
#include "ShaderObject.h"
#include "Vertex.h"
#include "Camera.h"
using namespace std;

#ifndef __WorldHandler_h__
#define __WorldHandler_h__


// #include "QuadTree.h"
// #include "Waypoints.h"
// #include "WallObject.h"

class WorldHandler
{
public:
		//QuadTree* quadTree;
		//Waypoints* waypoints;
		//WallObject* wallObject;
		WorldHandler();
		virtual ~WorldHandler();

		void Initialize(ID3D10Device* lDevice);
		void Draw( Camera* lCam );
private:
		//Waypoint mWaypoint[];
		void CreateVertexBuffer( ID3D10Buffer** lVB, int lSize  );
		void SetResources();
		void SetupVertices();

private:
		ID3D10Device* mDevice;
		ShaderObject* mShaderObject;

		D3DXMATRIX mWorldMatrix;
		D3DXMATRIX mViewProjMatrix;
		ID3D10Buffer* mVertexBuffer;

};

#endif
