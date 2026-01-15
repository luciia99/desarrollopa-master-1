#pragma once
#include "Entity.h"
#include "Player.h"
#include <GL/glut.h>
#include <cmath> // para abs

enum class EnemyType { MEDUSA, PULPO, TIBURON };

class Enemy : public Entity {
private:
    int health;
    Player* player; // puntero al jugador
    bool active;    // si el enemigo está activo
    EnemyType type; // tipo de enemigo
    float radiusInner;
    float radiusOuter;

public:
    Enemy(EnemyType t, Player* p)
        : Entity(), health(1), player(p), active(true), type(t)
    {
        switch (type) {
        case EnemyType::MEDUSA:
            radiusInner = 0.1f;
            radiusOuter = 0.2f;
            SetColor(Color(1.0f, 0.7f, 0.8f, 1.0f)); // rosa claro
            break;
        case EnemyType::PULPO:
            radiusInner = 0.15f;
            radiusOuter = 0.35f;
            SetColor(Color(0.6f, 0.0f, 0.2f, 1.0f)); // granate
            break;
        case EnemyType::TIBURON:
            radiusInner = 0.2f;
            radiusOuter = 0.45f;
            SetColor(Color(0.5f, 0.8f, 1.0f, 1.0f)); // azul claro
            break;
        }
    }

    bool IsDead() const { return health <= 0; }
    bool IsActive() const { return active; }

    void Damage(int d) {
        if (d > 0) {
            health -= d;
            if (health < 0) health = 0;
        }
    }

    virtual void Update(const float& time, const Vector3D& gravity) override {
        Entity::Update(time, gravity);
        if (!active) return;

        Vector3D pos = GetCoordinates();

        // mover siempre a la derecha hacia el jugador
        float speedX = 0.0009f;
        pos.SetX(pos.GetX() + speedX);
        SetCoordinates(pos);

        // colisión con jugador
        if (player) {
            Vector3D playerPos = player->GetCoordinates();
            float dx = std::abs(pos.GetX() - playerPos.GetX());
            float dy = std::abs(pos.GetY() - playerPos.GetY());
            float colDist = radiusOuter + 0.2f; // radio jugador aproximado

            if (dx < colDist && dy < colDist) {
                player->Damage(1);
                active = false;
            }
        }

        // si sale de la pantalla, desaparece
        if (pos.GetX() > 10.0f) active = false;
    }

    virtual void Render() override {
        if (!active) return;

        glPushMatrix();
        Vector3D pos = GetCoordinates();
        glTranslatef(pos.GetX(), pos.GetY(), pos.GetZ());

        Color c = GetColor();
        glColor4f(c.GetRedComponent(), c.GetGreenComponent(), c.GetBlueComponent(), c.GetAlphaComponent());

        glutSolidTorus(radiusInner, radiusOuter, 12, 24);
        glPopMatrix();
    }

    virtual Solid* Clone() override { return new Enemy(*this); }
    virtual ~Enemy() {}
};