#pragma once
#include "Solid.h"

// Clase base ligera para entidades del juego 
class Entity : public Solid {
public:
    Entity() : Solid() {}
    // Render obligatorio 
    virtual void Render() override {
    }
    virtual void Update(const float& time, const Vector3D& gravity) override {
        Solid::Update(time, gravity);
    }
    virtual Solid* Clone() override { return new Entity(*this); }
    virtual ~Entity() {}
};
