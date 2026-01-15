#pragma once
#include "Solid.h"
#include <GL/glut.h>

class Camera : public Solid
{
private:
    Vector3D position;  // x, y, z
    Vector3D rotation;  // rotX, rotY, rotZ

public:
    //constructor de argumento Vector3D que permite definir la pos de la cámara
    Camera(const Vector3D& pos = Vector3D()): Solid(), position(pos), rotation(0, 0, 0) {}

    //setters

    void SetPosition(const Vector3D& pos) { position = pos; }
    void SetRotation(const Vector3D& rot) { rotation = rot; }

	//getters

    Vector3D GetPosition() const { return position; }
    Vector3D GetRotation() const { return rotation; }

    void Render();
	void Update(const float& time);
	Solid* Clone() { return new Camera(*this); }
};
