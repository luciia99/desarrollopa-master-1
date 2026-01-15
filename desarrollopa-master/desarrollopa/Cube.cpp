#include "Cube.h"

Solid* Cube::Clone()
{
	return new Cube(*this);
}

void Cube::Render()
{
	glPushMatrix();

	Vector3D pos = GetCoordinates();
	Color c = GetColor();

	glTranslatef(pos.GetX(), pos.GetY(), pos.GetZ());

	glColor4f(c.GetRedComponent(), c.GetGreenComponent(), c.GetBlueComponent(), c.GetAlphaComponent());
	
	glutSolidCube(this->GetSize());
	glPopMatrix();
}
