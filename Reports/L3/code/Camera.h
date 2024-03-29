#ifndef CAMERA_H
#define CAMERA_H

#include "Utilities.h"

class Camera
{	
public:
	Camera();
	virtual ~Camera();
	void UpdateView();

	void SetPosition(D3DXVECTOR3 lPlayerPos);
	void Strafe(float d);
	void Walk(float d);
	void Pitch(float lAngle);
	void RotateY(float lAngle);

	void SetLens(float lFieldOfViewY, float lAspect, float lZValueNearPlane, float lZValueFarPlane);

	//Get Functions
	D3DXMATRIX GetView()const
	{
		return this -> mView;
	}
	D3DXMATRIX GetProjection()const
	{
		return this -> mProjection;
	}
	D3DXVECTOR3 GetPosition() const
	{
		return this -> mPosition;
	}
	
private:	
	D3DXVECTOR3 mPosition;	//Camera position
	D3DXVECTOR3 mRight;		//Orthogonal right vector to aim vector
	D3DXVECTOR3 mUp;		//Orthogonal up vector to aim
	D3DXVECTOR3 mAim;		//To where the camera is looking

	D3DXMATRIX mView;		//View Matrix
	D3DXMATRIX mProjection;	//Projection Matrix
};

#endif
