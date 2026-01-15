#pragma once
#include <GL/glut.h>
#include "Solid.h"

class Sphere : public Solid
{
private:
	float radius;
	int slices;
	int slacks;

public:

	Sphere() : radius(0.3f), slices(10), slacks(8)
	{
		SetCoordinates(Vector3D(0.0f, 0.0f, -2.0f));
		SetOrientation(Vector3D(0, 0, 0));
		SetColor(Color(0.2f, 0.3f, 0.4f, 1.0f));
	}

	inline float GetRadius() const { return this->radius; }
	inline int GetSlices() const { return this->slices; }
	inline int GetSlacks() const { return this->slacks; }

	void SetRadius(float radiusToSet) { this->radius = radiusToSet; }
	void SetSlices(int slicesToSet) { this->slices = slicesToSet; }
	void SetSlacks(int slacksToSet) { this->slacks = slacksToSet; }

	void Render();
	Solid* Clone();

};

