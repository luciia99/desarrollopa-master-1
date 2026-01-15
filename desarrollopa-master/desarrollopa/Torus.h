#pragma once
#include <GL/glut.h>
#include "Solid.h"

class Torus : public Solid
{
private:
	float innerRadius;
	float outerRadius;
	int sides;
	int rings;

public:
	//Como no tenemos los valores de los atos de torus los dejamos como parametros
	Torus()
	{
		SetCoordinates(Vector3D(0.0f, 0.0f, -2.0f));
		SetOrientation(Vector3D(0, 0, 0));
		SetColor(Color(0.2f, 0.3f, 0.4f, 1.0f));

	}

	inline float GetInnerRadius() const { return this->innerRadius; }
	inline float GetOuterRadius() const { return this->outerRadius; }
	inline int GetSides() const { return this->sides; }
	inline int GetRings() const { return this->rings; }

	void SetInnerRadius(float innerRadiusToSet) { this->innerRadius = innerRadiusToSet; }
	void SetOuterRadius(float outerRadiusToSet) { this->outerRadius = outerRadiusToSet; }
	void SetSides(int sidesToSet) { this->sides = sidesToSet; }
	void SetRings(int ringsToSet) { this->rings = ringsToSet; }

	void Render();
	Solid* Clone();

};

