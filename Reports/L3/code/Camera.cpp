#include "Camera.h"

Camera::Camera() 
{

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

void Camera::SetLens(float lFieldOfViewY, float lAspect, float lZValueNearPlane, float lZValueFarPlane)
{
	D3DXMatrixPerspectiveFovLH(&mProjection, lFieldOfViewY, lAspect, lZValueFarPlane, lZValueFarPlane);
}


//Get Functions
D3DXMATRIX Camera::GetView()const
{
	return mView;
}

D3DXMATRIX Camera::GetProjection()const
{
	return mProjection;
}

D3DXVECTOR3 Camera::GetPosition() const
{
	return this -> mPosition;
}