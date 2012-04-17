#include <exception>
using namespace std;

#ifndef __Camera_h__
#define __Camera_h__

// #include "BaseScreen.h"

class BaseScreen;
class Camera;

class Camera
{
	public:
		BaseScreen* baseScreen;

		void StartUp();
		void Shutdown();
		void UpdateView();
		D3DXVECTOR3 getMPosition();
	private:
		D3DXVECTOR3 mPosition;
		D3DXVECTOR3 mAim;

		void Camera();
};

#endif
