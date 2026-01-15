#pragma once
#include "Solid.h"
#include "Vector3D.h"

struct Particle {
    Solid* obj = nullptr;     
    Vector3D velocity;
    float life = 0.0f;         
};