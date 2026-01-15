#pragma once
#include <GL/glut.h>
#include "Solid.h"

class Triangle : public Solid
{
private:
	Vector3D vertices[3];
	Vector3D normales[3];
	Color colores[3];

	public:
		//el constructor por defecto inicializa los vértices, normales y colores
		//es necesario el const para que sea más eficiente
		//en la práctica utilizaremos el mismo color para los tres
		Triangle(const Vector3D& v0, const Vector3D& v1, const Vector3D& v2, const Vector3D& n0, const Vector3D& n1, const Vector3D& n2);
		
		void Render() override;
		Solid* Clone() override;

		//para model y modelloader
		Vector3D GetVertex0() const { return vertices[0]; }
		Vector3D GetVertex1() const { return vertices[1]; }
		Vector3D GetVertex2() const { return vertices[2]; }

		Vector3D GetNormal0() const { return normales[0]; }
		Vector3D GetNormal1() const { return normales[1]; }
		Vector3D GetNormal2() const { return normales[2]; }
		
		void SetColor(const Color& c) {
			colores[0] = colores[1] = colores[2] = c;
		}
		
};

