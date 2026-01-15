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
    bubble->SetRadius(0.1f);
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

    //obtenemos las matrices
    int viewport[4];
    double modelview[16];
    double projection[16];
    double worldX, worldY, worldZ;

    glGetIntegerv(GL_VIEWPORT, viewport);
    glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
    glGetDoublev(GL_PROJECTION_MATRIX, projection);

    //Invertimos Y (OpenGL)
    mouseY = viewport[3] - mouseY;

    gluUnProject(mouseX, mouseY, 0.0, modelview, projection, viewport, &worldX, &worldY, &worldZ);

    Vector3D origin = GetCoordinates();
    Vector3D target((float)worldX, (float)worldY, 0.0f);
    Vector3D direction = target - origin;

    //Normalizamos
    float len = sqrt(direction * direction);
    if (len < 0.0001f) return;
    direction = direction / len;

    //Colocamos el emisor en el jugador
    bubbleEmitter->SetCoordinates(origin);
    bubbleEmitter->SetSpeed(direction * 5.0f);

	//empezamos la emisión
    bubbleEmitter->Update(0.02f, Vector3D(0, 0, 0));
}

void Player::Update(const float& time, const Vector3D& gravity) {
    Entity::Update(time, gravity);
    if (bubbleEmitter)
        bubbleEmitter->Update(time, gravity);
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
    glColor4f(0.0f, 0.5f, 1.0f, 1.0f);
    glutSolidSphere(0.35f, 16, 16);
    glPopMatrix();

    if (bubbleEmitter) bubbleEmitter->Render();
}

Player::~Player() {
    delete bubbleEmitter;
}

