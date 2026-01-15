#pragma once
#include "Model.h"
#include <string>
#include <vector>

using namespace std;

class ModelLoader
{
private:
	//escala a aplicar al modelo
	float scale;
	//Model para almacenar el modelo generado
	Model model;
	//vértices que se leen del archivo
	vector <Vector3D> fileVertex;
	//normales que se leen del archivo
	vector <Vector3D> fileNormals;
	//almacenar los valores máximos y mínimos de X, Y y Z de los vértices leídos del archivo
	float maxX, minX, maxY, minY, maxZ, minZ;

	//devuelve el ancho del modelo cargado(devuelve un float)
	//diferencia entre el máximo y el mínimo en el eje X
	float getWidth() const;
	//diferencia entre el máximo y el mínimo en el eje Y
	float getHeight() const;
	//diferencia entre el máximo y el mínimo en el eje Z
	float getLength() const;

	void calcBoundaries(Vector3D vectorPoint);

	Triangle center(Triangle triangle);

	Vector3D parseObjLineToVector3D(const string& line);

	Triangle parseObjTriangle(const string& line);

public:
	//constructor
	ModelLoader();

	Model GetModel();

	float GetScale();
	void SetScale(float scaleToSet);

	//recibe una cadena de texto con la ruta del archivo obj a procesar
	bool LoadModel(const string& filename);

	void Clear();

};

