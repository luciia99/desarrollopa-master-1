#include "Cylinder.h"
#include <GL/glut.h>

void Cylinder::Render() {
	GLUquadricObj* quadricTemp = gluNewQuadric();
	glPushMatrix();

	Vector3D pos = GetCoordinates();
	Vector3D orient = GetOrientation();
	Color c = GetColor();

	glTranslatef(pos.GetX(), pos.GetY(), pos.GetZ());

	glColor4f(c.GetRedComponent(), c.GetGreenComponent(), c.GetBlueComponent(), c.GetAlphaComponent());

	glRotatef(orient.GetX(), 1.0, 0.0, 0.0);
	glRotatef(orient.GetY(), 0.0, 1.0, 0.0);
	glRotatef(orient.GetZ(), 0.0, 0.0, 1.0);


	gluCylinder(quadricTemp, this->GetBaseRadius(), this->GetTopRadius(), this->GetHeigth(), this->GetSlices(), this->GetStacks());
	glPopMatrix();
	gluDeleteQuadric(quadricTemp);

}

Solid* Cylinder::Clone() {
	return new Cylinder(*this);
}