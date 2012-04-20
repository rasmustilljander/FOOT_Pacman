#ifndef CAMERA_H
#define CAMERA_H
#include "Utilities.h"
class Camera
{
	// HEJ
	
public:
	Camera();
	virtual ~Camera();
	void UpdateView();
	void SetPosition(D3DXVECTOR3 lPlayerPos);
	void SetLens(float lFieldOfViewY, float lAspect, float lZValueNearPlane, float lZValueFarPlane);

	//Get Functions
	D3DXMATRIX GetView() const;
	D3DXMATRIX GetProjection() const;
	D3DXVECTOR3 GetPosition() const;

	
private:	
	D3DXVECTOR3 mPosition;	//Camera position
	D3DXVECTOR3 mRight;		
	D3DXVECTOR3 mUp;		//Up vector (0,1,0)
	D3DXVECTOR3 mAim;		//To where the camera is looking

	D3DXMATRIX mView;		//View Matrix
	D3DXMATRIX mProjection;	//Projection Matrix
};

#endif
