#include "Model.h"
#include <GL/glut.h>

void Model :: AddTriangle(const Triangle& triangle) {
	this->triangles.push_back(triangle);
}

void Model::Clear() {
	this->triangles.clear();
}

void Model::SetColor(Color colorToSet) {
	for(Triangle& triangle : triangles) {
		triangle.SetColor(colorToSet);
	}
	Solid::SetColor(colorToSet);
}

void Model::Render() {
	glPushMatrix();

	Vector3D pos = GetCoordinates();
	Vector3D orient = GetOrientation();
	Color c = GetColor();

	glTranslatef(pos.GetX(), pos.GetY(), pos.GetZ());

	glColor4f(c.GetRedComponent(), c.GetGreenComponent(), c.GetBlueComponent(), c.GetAlphaComponent());

	glRotatef(orient.GetX(), 1.0f, 0.0f, 0.0f);
	glRotatef(orient.GetY(), 0.0f, 1.0f, 0.0f);
	glRotatef(orient.GetZ(), 0.0f, 0.0f, 1.0f);

	//Por cada(Triangulo t en triángulos) t.Render();
	for(Triangle& t: this->triangles) {
		t.Render();
	}

	glPopMatrix();
}

Solid* Model::Clone() {
	return new Model(*this);
}