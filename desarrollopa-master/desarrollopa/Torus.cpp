#include "Torus.h"

Solid* Torus::Clone()
{
	return new Torus(*this);
}

void Torus::Render() 
{
	glPushMatrix();

	Vector3D pos = GetCoordinates();
	Vector3D orient = GetOrientation();
	Color c = GetColor();

	glTranslatef(pos.GetX(), pos.GetY(), pos.GetZ());

	glColor4f(c.GetRedComponent(), c.GetGreenComponent(), c.GetBlueComponent(), c.GetAlphaComponent());

	glRotatef(orient.GetX(), 1.0, 0.0, 0.0);
	glRotatef(orient.GetY(), 0.0, 1.0, 0.0);
	glRotatef(orient.GetZ(), 0.0, 0.0, 1.0);

	glutSolidTorus(this->GetInnerRadius(), this->GetOuterRadius(), this->GetSides(), this->GetRings());
	glPopMatrix();

}

