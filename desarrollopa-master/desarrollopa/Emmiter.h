#pragma once
#include <vector>
#include "Vector3D.h"
#include "Particle.h"
#include "EmmiterConfiguration.h"

class Emmiter {
private:
    std::vector<Particle> particles;
    Vector3D position;
    Vector3D speed;
    EmmiterConfiguration config;   

public:
    Emmiter(const EmmiterConfiguration& cfg);

    void EmitOnce();

    void SetCoordinates(const Vector3D& pos) { position = pos; }
    void SetSpeed(const Vector3D& spd) { speed = spd; }
    void SetPosition(const Vector3D& pos) { position = pos; }

    void Update(float dt, const Vector3D& gravity);
    void Render();

    const std::vector<Particle>& GetParticles() const { return particles; }
};
