#pragma once
#include "Solid.h"
#include "Triangle.h"
#include <vector>

using namespace std;

class Model : public Solid
{
private:
	vector<Triangle> triangles;

public:
	//constructor por defecto
	Model() = default;

	//permite añadir un triángulo al vector de triángulo
	//se añade por referencia constante para no hacer copias innecesarias
	void AddTriangle(const Triangle& triangle);

	// vacía el vector de triángulos
	void Clear();

	//recorre todos los triángulos del modelo y les fija el color a sus tres vértices
	void SetColor(Color colorToSet) override;

	void Render() override;

	Solid* Clone() override;

	// Cambia Vector3Df por Vector3D para que coincida con la definición existente
	void SetPosition(const Vector3D& pos) { SetCoordinates(pos); }

	// Añadir este método público a la clase Model
	const std::vector<Triangle>& GetTriangles() const { return triangles; }
};

