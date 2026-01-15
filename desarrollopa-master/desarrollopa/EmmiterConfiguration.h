#pragma once
#include "Solid.h"

class EmmiterConfiguration
{
private:
    int numParticulas;
	int emissionInterval;
	Solid* particula;

public:
	EmmiterConfiguration(int numPar, int emiInterv, Solid* particulaBase):numParticulas(numPar), emissionInterval(emiInterv), particula(particulaBase){}

	// Getters
	int GetNumParticulas() const { return numParticulas; }
	int GetEmissionInterval() const { return emissionInterval; }
	Solid* GetParticula() const { return particula; }

	// Setters
	void SetNumParticulas(int numPar) { this->numParticulas = numPar; }
	void SetPeriodoEmision(int emiInt) { this->emissionInterval = emiInt; }
	void SetParticula(Solid* par) { this->particula = par; }
};

