#pragma once
#include "Entity.h"
#include <GL/glut.h> 

class Player : public Entity {
private:
    int health;
    int score;
    float moveSpeed; // velocidad de movimiento vertical

public:
    Player() : Entity(), health(3), score(0), moveSpeed(0.2f) {}

    void AddScore(int s) { score += s; }
    int GetScore() const { return score; }
    void Damage(int d) { health -= d; if (health < 0) health = 0; }
    int GetHealth() const { return health; }

    // mover sin límites
    void MoveUp() {
        Vector3D pos = GetCoordinates();
        pos.SetY(pos.GetY() + moveSpeed);
        SetCoordinates(pos);
    }

    void MoveDown() {
        Vector3D pos = GetCoordinates();
        pos.SetY(pos.GetY() - moveSpeed);
        SetCoordinates(pos);
    }

    virtual void Update(const float& time, const Vector3D& gravity) override {
        // solo frenamos horizontal
        Vector3D speed = GetSpeed();
        speed.SetX(0);
        speed.SetZ(0);
        SetSpeed(speed);
    }

    virtual void Render() override {
        glPushMatrix();
        Vector3D pos = GetCoordinates();
        Color c = GetColor();
        glTranslatef(pos.GetX(), pos.GetY(), pos.GetZ());
        glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
        glutSolidSphere(0.35f, 16, 16);
        glPopMatrix();
    }

    virtual Solid* Clone() override { return new Player(*this); }
    virtual ~Player() {}
};