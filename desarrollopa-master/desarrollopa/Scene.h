#pragma once
#include <vector>
#include "Solid.h"
#include "Camera.h"

using namespace std;

class Scene
{
private:
	//vector de punteros a Solid
	vector<Solid*> gameObjects;

	//cámara de la escena
	Camera* camera;

	// boundary de la escena
	Vector3D boundary;

	//gravedad
	Vector3D gravity;



	void CheckBoundary(Solid* obj) {
		// Implementar la lógica para comprobar y manejar los límites de la escena
		// según las coordenadas del objeto y el boundary definido.
		Vector3D pos = obj->GetCoordinates();
		Vector3D speed = obj->GetSpeed();

		//Comprueba si la pos del eje X es mayor que la componente X de boundary
		if (pos.GetX() > boundary.GetX() || pos.GetX() < -boundary.GetX()) {
			//cambia el sentido de Speed en el eje X
			speed.SetX(-speed.GetX());
			obj->SetSpeed(speed);
		}

		//Lo mismo que antes pero en Y
		if (pos.GetY() > boundary.GetY() || pos.GetY() < -boundary.GetY()) {
			speed.SetY(-speed.GetY());
			obj->SetSpeed(speed);
		}

		//Lo mismo que antes pero en Z
		if (pos.GetZ() > boundary.GetZ() || pos.GetZ() < -boundary.GetZ()) {
			speed.SetZ(-speed.GetZ());
			obj->SetSpeed(speed);
		}
	}

public:

	//constructor de la escena
	Scene() : camera(new Camera(Vector3D(0.0f, 0.0f, 16.0f))), boundary(8.0f, 6.0f, 4.0f), gravity(0.0f, -0.00098f, 0.0f) {} //inicializa la cámara

	//método para añadir objetos a la escena
	void AddGameObject(Solid* obj) {
		//push_back es para añadir un obj al final del vector
		gameObjects.push_back(obj);
	}

	//métodos de acceso de boundary
	void SetBoundary(const Vector3D& b) { boundary = b; }
	Vector3D GetBoundary() const { return boundary; }
	
	void Render() {
    //Renderizar la cámara
    this->camera->Render();  // cámara ahora es un puntero

    for (int idx = 0; idx < this->gameObjects.size(); idx++) {
        this->gameObjects[idx]->Render();  // acceso por índice
    }
}

	void Update(const float& time) {
		camera->Update(time);
		for (Solid* obj : gameObjects) {
			if (obj) {
				obj->Update(time, gravity);
				CheckBoundary(obj);
			}
		}
	}
};

