#include "FirstPersonCamera.h"
#include <GL/glut.h>
#include <cmath>
Vector3D FirstPersonCamera::calcSpeedVector() {

	// Convertir ángulos de orientación de grados a radianes
	float yOrientation = degToRad(this->GetOrientation().GetY());
	float xOrientation = degToRad(this->GetOrientation().GetX());

	// Calcular componentes del vector de velocidad
	float x = cos(yOrientation) * sin(xOrientation);
	float y = sin(xOrientation);
	float z = -cos(yOrientation) * cos(xOrientation);

	Vector3D speedVector = Vector3D(x, y, z);
	return speedVector;
}

void FirstPersonCamera::ProcessKeyPressed(unsigned char key, int px, int py) {
	Vector3D position = GetPosition();
	Vector3D speedVector = calcSpeedVector();
	switch (key) {
	case 'w': // Mover hacia adelante
	case 'W':
		this->Update(this->cameraStep);
		break;
	case 's': // Mover hacia atrás
	case 'S':
		this->Update(-this->cameraStep);
		break;
		}
	}

void FirstPersonCamera::ProcessMouseMovement(int x, int y) {
	if (this->GetMouseX() >= 0 && this->GetMouseY() >= 0) {
		Vector3D orientation = this->GetOrientation() + Vector3D(y - this->GetMouseY(), x - this->GetMouseX(), 0);
		this->SetOrientation(orientation);
	}
	this->SetMouseX(x);
	this->SetMouseY(y);
}
void FirstPersonCamera::Update(const float& time) {
	this->SetSpeed(this->calcSpeedVector());
	Camera::Update(time);
}

void FirstPersonCamera::Render() {
	// Aplicar la transformación de la cámara
	glRotatef(this->GetOrientation().GetX(), 1, 0, 0); // Rotación en X
	glRotatef(this->GetOrientation().GetY(), 0, 1, 0); // Rotación en Y
	glRotatef(this->GetOrientation().GetZ(), 0, 0, 1); // Rotación en Z
	glTranslatef(-this->GetPosition().GetX(), -this->GetPosition().GetY(), -this->GetPosition().GetZ()); // Traslación
}


