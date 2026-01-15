#include "Player.h"
#include "Sphere.h"
#include "EmmiterConfiguration.h"
#include <GL/glut.h>
#include <cmath>

Player::Player()
    : Entity(), health(3), moveSpeed(0.2f), bubbleEmitter(nullptr)
{
    //hacemos que la particula base sea una esfera pequeña que será la burbuja
    Sphere* bubble = new Sphere();
    bubble->SetRadius(0.15f);
    bubble->SetColor(Color(0.4f, 0.7f, 1.0f, 0.7f));

    //Configuramos el emisor
    //partículas por emisión
    //intervalo (ms)
    EmmiterConfiguration config(1, 50, bubble );
    config.SetParticleType(ParticleType::WATER);
    config.SetParticleLife(1.5f);
    config.SetParticleSpeed(5.0f);
    config.SetParticleDamage(1);

    //Creamos el emisor
    bubbleEmitter = new Emmiter(config);
}

void Player::Shoot(int mouseX, int mouseY)
{
    if (!bubbleEmitter) return;

    // Solo necesitamos disparar horizontalmente
    Vector3D direction(-1.0f, 0.0f, 0.0f); // siempre horizontal izquierda

    // Configuramos la velocidad de la burbuja
    bubbleEmitter->SetSpeed(direction * 5.0f);

    // Emitimos la burbuja
    bubbleEmitter->EmitOnce();
}

void Player::Update(const float& time, const Vector3D& gravity)
{
    Entity::Update(time, gravity);

    if (bubbleEmitter)
    {
        bubbleEmitter->SetPosition(GetCoordinates());

        bubbleEmitter->Update(time, gravity);
    }
}

void Player::MoveUp()
{
    Vector3D pos = GetCoordinates();
    pos.SetY(pos.GetY() + moveSpeed);
    SetCoordinates(pos);
}

void Player::MoveDown()
{
    Vector3D pos = GetCoordinates();
    pos.SetY(pos.GetY() - moveSpeed);
    SetCoordinates(pos);
}

void Player::Damage(int d)
{
    health -= d;
    if (health < 0) health = 0;
}

int Player::GetHealth() const
{
    return health;
}

Solid* Player::Clone()
{
    return new Player(*this);
}


void Player::Render() {
    glPushMatrix();
    Vector3D pos = GetCoordinates();
    glTranslatef(pos.GetX(), pos.GetY(), pos.GetZ());

    // Opcional: escalar el modelo
     glScalef(0.4f, 0.4f, 0.4f);

    glColor4f(0.3f, 0.6f, 1.0f, 1.0f);
    waterdrop.Render(); // dibuja el modelo OBJ
    glPopMatrix();

    // Renderizar las burbujas
    if (bubbleEmitter)
        bubbleEmitter->Render();
}
Player::~Player() {
    delete bubbleEmitter;
}

