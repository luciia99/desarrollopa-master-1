#pragma once
#include <GL/glut.h>
#include "Solid.h"

class Teapot : public Solid
{
private:
	float size;

public:

	Teapot() 
	{
		SetCoordinates(Vector3D(0.0f, 0.0f, -2.0f));
		SetOrientation(Vector3D(30, 45, 60));
		SetColor(Color(0.2f, 0.3f, 0.4f, 1.0f));
		this->size = 0.4f;
	}

	inline float GetSize() const { return this->size; }
	void SetSize(float sizeToSet) { this->size = sizeToSet; }

	void Render();
	Solid* Clone();
};

