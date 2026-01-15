#pragma once
#include <GL/glut.h>
#include "Solid.h"

class Cuboid : public Solid
{
private:
	float length;
	float height;
	float width;

public:

	Cuboid() : length(0.2f), height(1.4f), width(1.0f)
	{
		SetCoordinates(Vector3D(0.0, 0.0, -2.0));
		SetOrientation(Vector3D(0, 0, 0));
		SetColor(Color(0.2f, 0.3f, 0.4f, 1.0f));
	}

	inline float GetLength() const { return this->length; }
	inline float GetHeight() const { return this->height; }
	inline float GetWidth() const { return this->width; }

	void SetLength(float lengthToSet) { this->length = lengthToSet; }
	void SetHeight(float heightToSet) { this->height = heightToSet; }
	void SetWidth(float widthToSet) { this->width = widthToSet; }

	void Render() override;
	Solid* Clone() override { return new Cuboid(*this); }
	~Cuboid() override = default;


};

