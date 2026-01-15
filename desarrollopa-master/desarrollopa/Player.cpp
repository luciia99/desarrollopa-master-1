#include "Player.h"
#include "Sphere.h"
#include "EmmiterConfiguration.h"
#include <GL/glut.h>
#include <cmath>
#include "ModelLoader.h"
#include <iostream>

Player::Player()
    : Entity(), health(3), moveSpeed(0.2f), bubbleEmitter(nullptr)
{
    // cargar y escalar modelo OBJ de burbuja
    ModelLoader loader;
    loader.SetScale(0.05f); // ajustar escala para coincidir con tamaño antiguo de esfera

    if (!loader.LoadModel("models/bubble.obj")) { // cargar archivo OBJ
        std::cerr << "Fallo al cargar bubble.obj" << std::endl;
        return;
    }

    // obtener modelo cargado y establecer color
    Model* bubbleModel = new Model(loader.GetModel());
    bubbleModel->SetColor(Color(0.4f, 0.7f, 1.0f, 0.7f));

    // configurar emisor con el modelo OBJ
    EmmiterConfiguration config(1, 50, bubbleModel);
    config.SetParticleType(ParticleType::WATER);  // tipo de partícula agua
    config.SetParticleLife(1.5f);                 // duración de cada partícula
    config.SetParticleSpeed(5.0f);                // velocidad inicial
    config.SetParticleDamage(1);                  // daño que inflige

    // crear emisor de burbujas
    bubbleEmitter = new Emmiter(config);
}

void Player::Shoot(int mouseX, int mouseY)
{
    if (!bubbleEmitter) return;

    // disparo siempre horizontal hacia la izquierda
    Vector3D direction(-1.0f, 0.0f, 0.0f);

    // configurar velocidad del emisor
    bubbleEmitter->SetSpeed(direction * 5.0f);

    // emitir una burbuja
    bubbleEmitter->EmitOnce();
}

void Player::Update(const float& time, const Vector3D& gravity)
{
    Entity::Update(time, gravity); // actualizar física y posición de la entidad

    if (bubbleEmitter)
    {
        bubbleEmitter->SetPosition(GetCoordinates()); // sincronizar posición con jugador
        bubbleEmitter->Update(time, gravity);         // actualizar partículas
    }
}

void Player::MoveUp()
{
    Vector3D pos = GetCoordinates();
    pos.SetY(pos.GetY() + moveSpeed); // incrementar posición vertical
    SetCoordinates(pos);
}

void Player::MoveDown()
{
    Vector3D pos = GetCoordinates();
    pos.SetY(pos.GetY() - moveSpeed); // decrementar posición vertical
    SetCoordinates(pos);
}

void Player::Damage(int d)
{
    health -= d;     // reducir vida
    if (health < 0)  // limitar vida mínima a 0
        health = 0;
}

int Player::GetHealth() const
{
    return health; // retornar vida actual
}

Solid* Player::Clone()
{
    return new Player(*this); // crear copia del jugador
}

void Player::Render() {
    glPushMatrix();
    Vector3D pos = GetCoordinates();
    glTranslatef(pos.GetX(), pos.GetY(), pos.GetZ());

    // opcional: escalar modelo
    glScalef(0.5f, 0.5f, 0.5f);

    glColor4f(0.3f, 0.6f, 1.0f, 1.0f);
    waterdrop.Render(); // dibujar modelo OBJ del jugador
    glPopMatrix();

    // renderizar burbujas
    if (bubbleEmitter)
        bubbleEmitter->Render();
}

Player::~Player() {
    delete bubbleEmitter; // liberar memoria del emisor de burbujas
}