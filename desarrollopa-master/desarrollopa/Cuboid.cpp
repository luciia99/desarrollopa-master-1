#include "Cuboid.h"
#include <GL/glut.h>

void Cuboid::Render()
{
	glPushMatrix();

	// Obtenemos los valores desde la clase base Solid
	Vector3D pos = GetCoordinates();
	Vector3D orient = GetOrientation();
	Color c = GetColor();

	glTranslatef(pos.GetX(), pos.GetY(), pos.GetZ());

	glColor4f(c.GetRedComponent(), c.GetGreenComponent(), c.GetBlueComponent(), c.GetAlphaComponent());
	
	glRotatef(orient.GetX(), 1.0, 0.0, 0.0);
	glRotatef(orient.GetY(), 0.0, 1.0, 0.0);
	glRotatef(orient.GetZ(), 0.0, 0.0, 1.0);

	glScalef(this->GetLength(), this->GetHeight(), this->GetWidth());
	glutSolidCube(1.0);
	glPopMatrix();
}