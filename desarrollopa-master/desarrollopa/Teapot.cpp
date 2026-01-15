#include "Teapot.h"

Solid* Teapot::Clone()
{
	return new Teapot(*this);
}

void Teapot::Render()
{
	glPushMatrix();
	// Usamos los getters de Solid
	Vector3D pos = GetCoordinates();
	Vector3D orient = GetOrientation();
	Color c = GetColor();

	// Aplicamos transformación
	glTranslatef(pos.GetX(), pos.GetY(),pos.GetZ());

	//Color
	glColor4f(c.GetRedComponent(), c.GetGreenComponent(), c.GetBlueComponent(), c.GetAlphaComponent());
	
	glRotatef(orient.GetX(), 1.0, 0.0, 0.0);
	glRotatef(orient.GetY(), 0.0, 1.0, 0.0);
	glRotatef(orient.GetZ(), 0.0, 0.0, 1.0);
	glutSolidTeapot(this->GetSize());
	glPopMatrix();
}
