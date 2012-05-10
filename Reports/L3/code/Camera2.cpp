#include "Camera2.h"

Camera2::Camera2():	dV( D3DXVECTOR3(0,0,1) ), 
					dU( D3DXVECTOR3(0,1,0) ),
					eye( D3DXVECTOR3(0,0,0) ),
					view( D3DXVECTOR3(0,0,1) ),
					up( D3DXVECTOR3(0,1,0) ),
					forward( D3DXVECTOR3(0,0,1) ),
					strafeRight( D3DXVECTOR3(1,0,0) ),
					heading(0),
					pitch(0),
					movementSpeed(1)
{	
	//set matrices to identity
	D3DXMatrixIdentity( &viewMatrix );
	D3DXMatrixIdentity( &projectionMatrix );

	//initialize movement toggles
	movementToggles[0] = 0;
	movementToggles[1] = 0;
	movementToggles[2] = 0;
	movementToggles[3] = 0;
	camTimer.Start();
}

Camera2::~Camera2()
{

}


void Camera2::setPerspectiveProjectionLH(float FOV, float aspectRatio, float zNear, float zFar)
{
	//convert FOV from degrees to radians
	FOV = FOV * (float) DEG_TO_RAD;

	D3DXMatrixPerspectiveFovLH( &projectionMatrix, FOV, aspectRatio, zNear, zFar );
}

void Camera2::updateView()
{	
	//create rotation matrix
	D3DXMatrixRotationYawPitchRoll( &rotationMatrix, heading, pitch, 0 );

	//create new view and up vectors
	D3DXVec3TransformCoord( &view, &dV, &rotationMatrix );
	D3DXVec3TransformCoord( &up, &dU, &rotationMatrix );

	//create new forward and strafe vectors
	D3DXVec3Normalize( &forward, &view );	
	D3DXVec3Cross( &strafeRight, &up, &view );
	D3DXVec3Normalize( &strafeRight, &strafeRight );

	//take into account eye position
	view = eye + view;
	
	//update view matrix
	D3DXMatrixLookAtLH( &viewMatrix, &eye, &view, &up );

}
void Camera2::SetPosition(float x, float y, float z)
{
	eye.x = x;
	eye.z = z;
	eye.y = y;
	updateView();
}

void Camera2::setPositionAndView(float x, float y, float z, float hDeg, float pDeg)
{
	//set eye coordinates
	eye.x = x;
	eye.z = z;
	eye.y = y;

	//set heading and pitch
	adjustHeadingPitch( hDeg * (float) DEG_TO_RAD, pDeg * (float) DEG_TO_RAD );

	//update view 
	updateView();
}

void Camera2::adjustHeadingPitch( float hRad, float pRad )
{
	heading += hRad;
	pitch += pRad;

	//value clamping - keep heading and pitch between 0 and 2 pi
	if ( heading > TWO_PI ) heading -= (float) TWO_PI;
	else if ( heading < 0 ) heading = (float) TWO_PI + heading;
	
	if ( pitch > TWO_PI ) pitch -= (float) TWO_PI;
	else if ( pitch < 0 ) pitch = (float) TWO_PI + pitch;
}


void Camera2::setMovementToggle( int i, int v )
{
	movementToggles[i] = v;
}

void Camera2::setMovementSpeed( float s )
{
	movementSpeed = s;
}


void Camera2::update()
{
	camTimer.Tick();
	//get current elapsed time
	double t = camTimer.GetDeltaTime();
	
	//update position - 1.5 unit per second
	eye +=	(float) t * ( movementToggles[0] + movementToggles[1] ) * movementSpeed * forward + 
			(float) t * ( movementToggles[2] + movementToggles[3] ) * movementSpeed * strafeRight;
	eye.y = gPlayerYPosition;

	//update view
	updateView();

	//reset timer
}

void Camera2::setHeightY( float h[])
{
	heightY = h;
}

void Camera2::calculateY()
{
	
}