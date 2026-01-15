#pragma once
#include "Solid.h"

enum class ParticleType
{
	WATER = 0,
	FIRE = 1
};

class EmmiterConfiguration
{
private:
    int numParticulas;
	int emissionInterval;
	Solid* particula;

	//añadimos los nuevos parámetros a la partícula
	ParticleType particleType;
	//sg
	float particleLife;
	//uds por sg
	float particleSpeed;
	//daño que inflinge si se aplica
	int particleDamage;

public:
	EmmiterConfiguration(int numPar, int emiInterv, Solid* particulaBase):numParticulas(numPar), emissionInterval(emiInterv), particula(particulaBase),
		particleType(ParticleType::WATER), particleLife(1.0f), particleSpeed(3.0f), particleDamage(1){}

	// Getters
	int GetNumParticulas() const { return numParticulas; }
	int GetEmissionInterval() const { return emissionInterval; }
	Solid* GetParticula() const { return particula; }

	ParticleType GetParticleType() const { return particleType; }
	float GetParticleLife() const { return particleLife; }
	float GetParticleSpeed() const { return particleSpeed; }
	int GetParticleDamage() const { return particleDamage; }

	// Setters
	void SetNumParticulas(int numPar) { this->numParticulas = numPar; }
	void SetPeriodoEmision(int emiInt) { this->emissionInterval = emiInt; }
	void SetParticula(Solid* par) { this->particula = par; }

	void SetParticleType(ParticleType t) { this->particleType = t; }
	void SetParticleLife(float l) { this->particleLife = l; }
	void SetParticleSpeed(float s) { this->particleSpeed = s; }
	void SetParticleDamage(int d) { this->particleDamage = d; }
};

