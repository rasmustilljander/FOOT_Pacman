#ifndef _CAMERA
#define _CAMERA

#include "Utilities.h"
#include "GameTimer.h"


class Camera2
{
private:
		
	//view parameters
	float heading, pitch;
	float* heightY;

	//matrices
	D3DXMATRIX viewMatrix;
	D3DXMATRIX projectionMatrix;	
	D3DXMATRIX rotationMatrix;
		
	//view vectors
	const D3DXVECTOR3 dV, dU;
	D3DXVECTOR3 eye, view, up;

	//movement vectors and movement toggles
	D3DXVECTOR3 forward, strafeRight;		
	int movementToggles[4];					//fwrd, bck, strfLft, strfRght
	float movementSpeed;

	//camera timer for movement
	GameTimer camTimer;	

	//--------------------------------------------------------------------------------
	//Methods
	//--------------------------------------------------------------------------------

public:

	Camera2();
	virtual ~Camera2();

	//set projection methods
	void setPerspectiveProjectionLH( float FOV, float aspectRatio, float zNear, float zFar );
			
	//camera positioning methods
	void setPositionAndView( float x, float y, float z, float hDeg, float pDeg );
	void adjustHeadingPitch( float hRad, float pRad );
	void setMovementToggle( int i, int v );	
	void setMovementSpeed( float s );	

	void update();	

	void setHeightY(float h[]);

	//get methods	
	D3DXMATRIX&		getViewMatrix(){ return viewMatrix; }
	D3DXMATRIX&		getProjectionMatrix(){ return projectionMatrix; }
	D3DXVECTOR3&	getCameraPosition(){ return eye; }

private:

	//create view, forward, strafe vectors from heading/pitch
	void updateView();
	void calculateY();
};

#endif