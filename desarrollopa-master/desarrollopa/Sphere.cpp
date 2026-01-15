#include "Sphere.h"

Solid* Sphere::Clone()
{
	return new Sphere(*this);
}

void Sphere::Render()
{
	glPushMatrix();

	//Obtenemos los valores desde la clase base Solid
	Vector3D pos = GetCoordinates();
	Color c = GetColor();

	glTranslatef(pos.GetX(), pos.GetY(), pos.GetZ());
	glColor4f(c.GetRedComponent(),c.GetGreenComponent(), c.GetBlueComponent(), c.GetAlphaComponent());
	glutSolidSphere(this->GetRadius(), this->GetSlices(), this->GetSlacks());
	glPopMatrix();
}
