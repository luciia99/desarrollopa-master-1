#pragma once
#include "Entity.h"

class Projectile : public Entity {
private:
    int damage;
    float life; // tiempo de vida en segundos
public:
    Projectile() : Entity(), damage(1), life(5.0f) {}
    void SetDamage(int d) { damage = d; }
    int GetDamage() const { return damage; }

    virtual void Update(const float& time, const Vector3D& gravity) override {
        Entity::Update(time, gravity);
        life -= time;
        // Si life <= 0, el gestor de la escena lo elimina
    }
    virtual void Render() override {}
    virtual Solid* Clone() override { return new Projectile(*this); }
    virtual ~Projectile() {}
};
