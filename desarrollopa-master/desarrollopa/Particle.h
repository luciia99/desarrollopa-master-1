#pragma once
#include "Solid.h"
#include "Vector3D.h"

struct Particle {
    Solid* obj;      // objeto visual (burbuja o fuego)
    Vector3D velocity;
    float life;      // tiempo de vida en segundos
};


