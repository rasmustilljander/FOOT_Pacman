#include <exception>
using namespace std;

#include "Camera.h"
#include "BaseScreen.h"

void Camera::Camera() {
}

void Camera::StartUp() {
	throw "Not yet implemented";
}

void Camera::Shutdown() {
	throw "Not yet implemented";
}

void Camera::UpdateView() {
	throw "Not yet implemented";
}

D3DXVECTOR3 Camera::getMPosition() {
	return this->mPosition;
}

