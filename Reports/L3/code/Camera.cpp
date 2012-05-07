#include "Camera.h"

Camera::Camera() 
{
	mPosition	= D3DXVECTOR3(0.0f, 200.0f, -400.0f);
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
	D3DXMatrixLookAtLH(&mView, &mPosition, &mAim, &mUp);
}

void Camera::SetPosition(D3DXVECTOR3 lPlayerPos)
{
	mPosition = lPlayerPos;
}

//Move camera using keyboardbuttons 'A' or 'D'
void Camera::Strafe(float d)
{
	D3DXVECTOR3 lRight;
	D3DXVec3Normalize(&lRight, &mRight);
	mPosition += lRight * d;
}

//Move camera using keyboardbuttons 'W' or 'S'
void Camera::Walk(float d)
{
	D3DXVECTOR3 lAim;
	D3DXVec3Normalize(&lAim, &mAim);
	mPosition += lAim * d;
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
	lFieldOfViewY = lFieldOfViewY * (float) DEG_TO_RAD;
	D3DXMatrixPerspectiveFovLH(&mProjection, lFieldOfViewY, lAspect, lZValueNearPlane, lZValueFarPlane);
}