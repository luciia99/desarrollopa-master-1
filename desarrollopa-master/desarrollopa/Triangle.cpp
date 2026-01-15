#include "Triangle.h"

//método Clone de la clase Triangle
Solid* Triangle::Clone()
{
	return new Triangle(*this);
}

//constructor de la clase Triangle
Triangle::Triangle(const Vector3D& v0, const Vector3D& v1, const Vector3D& v2, const Vector3D& n0, const Vector3D& n1, const Vector3D& n2)
{
	//inicializamos los vértices, normales y colores
	vertices[0] = v0;
	vertices[1] = v1;
	vertices[2] = v2;

	normales[0] = n0;
	normales[1] = n1;
	normales[2] = n2;

	colores[0] = colores[1] = colores[2] = Color(1.0f, 1.0f, 1.0f, 1.0f);
}

//método Render de la clase Triangle
void Triangle::Render() {
	glBegin(GL_TRIANGLES);
	//en vez de hacerlo vertice por vertice añadimos un bucle for que recorra cada uno
	for(int i = 0; i < 3; i++)
	{
		glColor4f(colores[i].GetRedComponent(), colores[i].GetGreenComponent(), colores[i].GetBlueComponent(), colores[i].GetAlphaComponent());
		glNormal3f(normales[i].GetX(), normales[i].GetY(), normales[i].GetZ());
		glVertex3f(vertices[i].GetX(), vertices[i].GetY(), vertices[i].GetZ());
	}
	glEnd();
}