#pragma once
#include "Entity.h"
#include "Player.h"
#include "Emmiter.h"

class Enemy : public Entity {
private:
    int health;
    Player* player;
    bool active;
    float radius;
    //añadimos el emisor de fuego
    Emmiter* fireEmitter;
    //temporizador de disparo
    float fireTimer;     
    //tiempo entre disparos
    float fireInterval;       

public:
    Enemy(Player* p);

    bool IsActive() const { return active; }
    bool IsDead() const { return health <= 0; }

    void Damage(int d);
    void Deactivate() { active = false; }
    float GetRadius() const { return radius; }

    Emmiter* GetFireEmitter() const { return fireEmitter; }

    virtual void Update(const float& time, const Vector3D& gravity) override;
    virtual void Render() override;
    virtual Solid* Clone() override;

    virtual ~Enemy();
};
