#pragma once
#include "Entity.h"
#include "Emmiter.h"
#include "Model.h"

class Player : public Entity {
private:
    int health;
    float moveSpeed;
	Model waterdrop;
    //el emisor de burbujas
    Emmiter* bubbleEmitter;  

public:
    Player();

    void MoveUp();
    void MoveDown();
    //función para disparar las burbujas hacia el click
    void Shoot(int mouseX, int mouseY); 

    void Damage(int d);
    int GetHealth() const;
    void SetHealth(int h) { health = h; }
    Emmiter* GetBubbleEmitter() const { return bubbleEmitter; }

    void SetWaterdrop(const Model& model);
    virtual void Update(const float& time, const Vector3D& gravity) override;
    virtual void Render() override;
    virtual Solid* Clone() override;

    virtual ~Player();
};
