#include "Camera.h"

Camera::Camera() 
{
	mPosition	= D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	mRight		= D3DXVECTOR3(1.0f, 0.0f, 0.0f);
	mUp			= D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	mAim		= D3DXVECTOR3(0.0f, 0.0f, 1.0f);

	D3DXMatrixIdentity(&mView);
	D3DXMatrixIdentity(&mProjection);
}

Camera::~Camera()
{

}

void Camera::UpdateView() 
{
	// Keep camera's axes orthogonal to each other and of unit length.
	D3DXVec3Normalize(&mAim, &mAim);

	//
	D3DXVec3Cross(&mUp, &mAim, &mRight);			
	D3DXVec3Normalize(&mUp, &mUp);	

	//
	D3DXVec3Cross(&mRight, &mUp, &mAim);			
	D3DXVec3Normalize(&mRight, &mRight);

	// Fill in the view matrix entries.
	float x = -D3DXVec3Dot(&mPosition, &mRight);
	float y = -D3DXVec3Dot(&mPosition, &mUp); 
	float z = -D3DXVec3Dot(&mPosition, &mAim);

	mView(0,0) = mRight.x; 
	mView(1,0) = mRight.y; 
	mView(2,0) = mRight.z; 
	mView(3,0) = x;   

	mView(0,1) = mUp.x;
	mView(1,1) = mUp.y;
	mView(2,1) = mUp.z;
	mView(3,1) = y;  

	mView(0,2) = mAim.x; 
	mView(1,2) = mAim.y; 
	mView(2,2) = mAim.z; 
	mView(3,2) = z;   

	mView(0,3) = 0.0f;
	mView(1,3) = 0.0f;
	mView(2,3) = 0.0f;
	mView(3,3) = 1.0f;
}

void Camera::SetPosition(D3DXVECTOR3 lPlayerPos)
{
	mPosition = lPlayerPos;
}

//Move camera using keyboardbuttons 'A' or 'D'
void Camera::Strafe(float d)
{
	mPosition += mRight * d;
//	Left (A)
//	mPos1 = mPos0 + mRight * (-(movementspeed * dt))
//Right (D)
//	mPos1 = mPos0 + mRight * ((movementspeed * dt))
}

//Move camera using keyboardbuttons 'W' or 'S'
void Camera::Walk(float d)
{
	mPosition += mAim * d;
//Forward (W)
//	mPos1 = mPos0 + mAt * ((movementspeed * dt))
//Back (S)
//	mPos1 = mPos0 + mAt * (-(movementspeed * dt))
}

void Camera::Pitch(float lAngle)
{
	D3DXMATRIX lMatrix;
	D3DXMatrixRotationAxis(&lMatrix, &mRight, lAngle);

	D3DXVec3TransformNormal(&mUp, &mUp, &lMatrix);
	D3DXVec3TransformNormal(&mAim, &mAim, &lMatrix);
}

void Camera::RotateY(float lAngle)
{
	D3DXMATRIX lMatrix;
	D3DXMatrixRotationY(&lMatrix, lAngle);

	D3DXVec3TransformNormal(&mRight, &mRight, &lMatrix);
	D3DXVec3TransformNormal(&mUp, &mUp, &lMatrix);
	D3DXVec3TransformNormal(&mAim, &mAim, &lMatrix);
}

void Camera::SetLens(float lFieldOfViewY, float lAspect, float lZValueNearPlane, float lZValueFarPlane)
{
	D3DXMatrixPerspectiveFovLH(&mProjection, lFieldOfViewY, lAspect, lZValueFarPlane, lZValueFarPlane);
}