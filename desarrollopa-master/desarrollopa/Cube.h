#pragma once
#include <GL/glut.h>
#include "Solid.h"

class Cube:public Solid
{
private:
	float size;

public:

	Cube()
	{
		SetCoordinates(Vector3D(0.0f, 0.0f, -2.0f));
		SetOrientation(Vector3D(0, 0, 0));
		SetColor(Color(0.2f, 0.3f, 0.4f, 1.0f));
		this->size = 0.5;
	}

	float GetSize() const { return this->size; }
	void SetSize(float sizeToSet) { this->size = sizeToSet; }

	void Render();

	Solid* Clone();
};

