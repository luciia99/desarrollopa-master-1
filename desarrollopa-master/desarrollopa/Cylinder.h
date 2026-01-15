#pragma once
#include <GL/glut.h>
#include "Solid.h"

class Cylinder :public Solid
{
private:
	float baseRadius;
	float topRadius;
	float heigth;
	int slices;
	int stacks;

public:
	//Como no tenemos los valores de los atos de torus los dejamos como parametros
	Cylinder() : baseRadius(0.3f), topRadius(0.3f), heigth(1.0f), slices(12), stacks(1)
	{
		SetCoordinates(Vector3D(0.0f, 0.0f, -2.0f));
		SetOrientation(Vector3D(0, 0, 0));
		SetColor(Color(0.2, 0.3, 0.4, 1.0));

	}

	inline float GetBaseRadius() const { return this->baseRadius; }
	inline float GetTopRadius() const { return this->topRadius; }
	inline float GetHeigth() const { return this->heigth; }
	inline int GetSlices() const { return this->slices; }
	inline int GetStacks() const { return this->stacks; }

	void SetBaseRadius(float baseRadiusToSet) { this->baseRadius = baseRadiusToSet; }
	void SetTopRadius(float topRadiusToSet) { this->topRadius = topRadiusToSet; }
	void SetHeigth(float heigthToSet) { this->heigth = heigthToSet; }
	void SetSlices(int slicesToSet) { this->slices = slicesToSet; }
	void SetStacks(int stacksToSet) { this->stacks = stacksToSet; }

	void Render();
	Solid* Clone();


};

