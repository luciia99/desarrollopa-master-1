#include "ModelLoader.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cmath>
#include <exception>

using namespace std;

//constructor
ModelLoader::ModelLoader() {
	//escala neutra
	scale = 1.0f;
	//inicializa el loader en estado válido
	Clear();
}

Model ModelLoader::GetModel() { return model; }

float ModelLoader::GetScale() { return scale; }

void ModelLoader::SetScale(float scaleToSet) { scale = scaleToSet; }

//reiniciar coompletamente modelloader y dejarlo como nuevo
void ModelLoader::Clear() {
	//borramos todos los elementos de los vectores
	fileVertex.clear();
	fileNormals.clear();
	//vaciamos el modelo, no hay geometría cargada
	model.Clear();

	//AÑADIR EXPLICACION
	minX = minY = minZ = 1000000000; //1e9f
	maxX = maxY = maxZ = -1000000000;
}

float ModelLoader::getWidth() const { return maxX - minX; }
float ModelLoader::getHeight() const { return maxY - minY; }
float ModelLoader::getLength() const { return maxZ - minZ; }

void ModelLoader::calcBoundaries(Vector3D vectorPoint) {
	this->maxX = fmax(this->maxX, vectorPoint.GetX());
	this->maxY = fmax(this->maxY, vectorPoint.GetY());
	this->maxZ = fmax(this->maxZ, vectorPoint.GetZ());
	this->minX = fmin(this->minX, vectorPoint.GetX());
	this->minY = fmin(this->minY, vectorPoint.GetY());
	this->minZ = fmin(this->minZ, vectorPoint.GetZ());
}


Vector3D ModelLoader::parseObjLineToVector3D(const string& line) {
	//En el archivo obj, los vértices o las normales se define mediante las 3 coords. de un vector.
	//Éste método convierte estas coords. a un obj de la clase Vector3D
	//el formato de un vértice en el obj es: v -0.091741 0.641907 0.606832
	
	string typeOfPoint;
	float xCoordinate, yCoordinate, zCoordinate;
	istringstream stringStream(line);
	stringStream >> typeOfPoint >> xCoordinate >> yCoordinate >> zCoordinate;
	Vector3D vectorPoint(xCoordinate, yCoordinate, zCoordinate);
	return vectorPoint * this->GetScale();
}

std::vector<Triangle> ModelLoader::parseObjFace(const std::string& line) {
	std::vector<Triangle> triangles; // vector donde guardaremos los triángulos resultantes
	std::istringstream ss(line);
	std::string token;
	ss >> token; // descartamos la "f"

	std::vector<int> vertexIndices;
	std::vector<int> normalIndices;

	// leer cada vértice de la cara
	while (ss >> token) {
		int v = 0, n = 0;
		size_t firstSlash = token.find('/');
		size_t lastSlash = token.rfind('/');

		v = std::stoi(token.substr(0, firstSlash)); // índice de vértice

		if (firstSlash != std::string::npos) {
			n = std::stoi(token.substr(lastSlash + 1)); // índice de normal
		}

		vertexIndices.push_back(v);
		normalIndices.push_back(n);
	}

	// triangulación tipo “fan”: crea triángulos desde el primer vértice
	for (size_t i = 1; i + 1 < vertexIndices.size(); ++i) {
		Vector3D v0 = fileVertex[vertexIndices[0] - 1];
		Vector3D v1 = fileVertex[vertexIndices[i] - 1];
		Vector3D v2 = fileVertex[vertexIndices[i + 1] - 1];

		Vector3D n0 = (normalIndices[0] > 0) ? fileNormals[normalIndices[0] - 1] : Vector3D(0, 1, 0);
		Vector3D n1 = (normalIndices[i] > 0) ? fileNormals[normalIndices[i] - 1] : Vector3D(0, 1, 0);
		Vector3D n2 = (normalIndices[i + 1] > 0) ? fileNormals[normalIndices[i + 1] - 1] : Vector3D(0, 1, 0);

		triangles.push_back(Triangle(v0, v1, v2, n0, n1, n2));
	}

	return triangles;
}
Triangle ModelLoader::parseObjTriangle(const string& line) {
	//En el archivo obj, las caras se definen a partir de los vértices y normales previos.
	//Éste método convierte esa info en un objeto de la clase Triangle
	//el formato de una cara (en este caso un triángulo) en el obj es: f 7//10 9//10 3//10

	char c; //caracter para leer lo que no nos interesa
	int idxVertex0, idxVertex1, idxVertex2;
	int idxNormal0, idxNormal1, idxNormal2;

	istringstream stringStream(line);
	stringStream >> c; //f
	stringStream >> idxVertex0 >> c >> c >> idxNormal0; //ejemplo: 7//10
	stringStream >> idxVertex1 >> c >> c >> idxNormal1; 
	stringStream >> idxVertex2 >> c >> c >> idxNormal2;

	Vector3D vertex0 = this->fileVertex[idxVertex0 - 1];
	Vector3D vertex1 = this->fileVertex[idxVertex1 - 1];
	Vector3D vertex2 = this->fileVertex[idxVertex2 - 1];
	Vector3D normal = this->fileNormals[idxNormal0- 1]; //las 3 normales son iguales

	Triangle parsedTriangle(vertex0, vertex1, vertex2, normal, normal, normal);

	return parsedTriangle;
}


Triangle ModelLoader::center(Triangle triangle)
{
	Vector3D modelCenter( this->minX + this->getWidth() / 2.0f,
		this->minY + this->getHeight() / 2.0f,
		this->minZ + this->getLength() / 2.0f);

	Triangle centeredTriangle(
		triangle.GetVertex0() - modelCenter,
		triangle.GetVertex1() - modelCenter,
		triangle.GetVertex2() - modelCenter,
		triangle.GetNormal0(),
		triangle.GetNormal1(),
		triangle.GetNormal2());
	return centeredTriangle;
}

bool ModelLoader::LoadModel(const string& filePath)
{
	try
	{
		ifstream objFile(filePath);
		if (objFile.is_open())
		{
			string line;
			int count = 0;
			while (getline(objFile, line))
			{
				if (line[0] == 'v' && line[1] == 'n') //ejemplo: vn 0.000 0.3603 -0.9328 => normal
				{
					Vector3D normal = this->parseObjLineToVector3D(line);
					this->fileNormals.push_back(normal);
				}
				else if (line[0] == 'v') //EJEMPLO: V -0.091741 0.641907 0.606832 => vértice
				{
					Vector3D vertex = this->parseObjLineToVector3D(line);
					this->calcBoundaries(vertex);
					this->fileVertex.push_back(vertex);
				}
				else if (line[0] == 'f') //ejemplo: f 2//4 5//4 6//4 => cara, triángulo
				{
					std::vector<Triangle> tris = parseObjFace(line);
					for (Triangle& t : tris) {
						model.AddTriangle(center(t));
					}
					//yhis->model.AddTriangle(triangle)
				}
			}
			objFile.close();
		}
		//si hay un error
		else
		{
			cout << "No se ha podido abrir el archivo: " << filePath << endl;
			return false;
		}
	}
	catch (exception& ex)
	{
		cout << "Excepción al procesar el archivo: " << filePath << endl;
		cout << ex.what() << endl;
		return false;
	}
	return true;
}

