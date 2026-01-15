#pragma once
#include "Solid.h"
#include <vector>
#include <chrono>
#include "EmmiterConfiguration.h"

using namespace std;
using namespace chrono;

class Emmiter : public Solid
{
private:
	//guarda la configuración del emisor
	EmmiterConfiguration configuracion;
	//puntero a solid que guarda las refs a las partículas generadas
	vector<Solid*> particulas;
	//almacena tiempo de inicio de la emisión
	milliseconds initialMilliseconds;
	//registra el tiempo de cada emisión de una nueva partícula
	long lastUpdateTime;
	//guardo la base de la burbuja
	Solid* baseParticula;

public:

	Emmiter(EmmiterConfiguration& config);

	//Destructor
	~Emmiter();

	void Render();
	void Update(const float& time);
	//asi hacemos una copia profunda del emisor
	Solid* Clone() override { return nullptr; }
};

