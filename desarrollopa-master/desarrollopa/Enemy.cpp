#include "Enemy.h"
#include <cmath>
#include <GL/glut.h>
#include "Sphere.h"
#include "EmmiterConfiguration.h"

//las llamas lanzan el fuego cada 1.5 segundos
Enemy::Enemy(Player* p) : Entity(), health(1), player(p), active(true), radius(0.35f),
    fireEmitter(nullptr), fireTimer(0.0f), fireInterval(1.5f){
    SetColor(Color(1.0f, 0.4f, 0.1f, 1.0f)); // llamita

    //la particula base va a ser un fuego
    Sphere* fire = new Sphere();
    fire->SetRadius(0.15f);
    fire->SetColor(Color(1.0f, 0.2f, 0.0f, 0.9f));

    //partículas por disparo
    //intervalo interno
    EmmiterConfiguration config(1, 50, fire);

    config.SetParticleType(ParticleType::FIRE);
    config.SetParticleLife(0.8f);
    config.SetParticleSpeed(1.0f);
    config.SetNumParticulas(6);

    fireEmitter = new Emmiter(config);
}


void Enemy::Damage(int d){
    health -= d;
    if (health <= 0){
        health = 0;
        active = false;
    }
}

void Enemy::Update(const float& time, const Vector3D& gravity){
    if (!active) return;
    //movimiento
    Vector3D pos = GetCoordinates();
    pos.SetX(pos.GetX() + 5.0f * time); // se mueve hacia la derecha
    SetCoordinates(pos);

	//disparo de fuego
    fireTimer += time;
    if (fireEmitter && player && fireTimer >= fireInterval){
        fireTimer = 0.0f;

        Vector3D origin = GetCoordinates();
        Vector3D target = player->GetCoordinates();
        Vector3D dir = target - origin;

        float len = sqrt(dir * dir);
        if (len > 0.0001f) dir = dir / len;

        fireEmitter->SetCoordinates(origin);
        fireEmitter->SetSpeed(dir);

		fireEmitter->EmitOnce();
    }

    //Actualizamos las partículas
    if (fireEmitter) fireEmitter->Update(time, gravity);

    // Colisión directa con jugador
    if (player){
        Vector3D pPos = player->GetCoordinates();
        Vector3D diff = pos - pPos;
        float dist2 = diff * diff;
        float colDist = radius + 0.35f;

        if (dist2 < colDist * colDist){
            player->Damage(1);
            active = false;
        }
    }

    // Sale de pantalla
    if (pos.GetX() > 10.0f)
        active = false;
}

void Enemy::Render(){
    if (!active) return;

    glPushMatrix();
    Vector3D pos = GetCoordinates();
    glTranslatef(pos.GetX(), pos.GetY(), pos.GetZ());

    Color c = GetColor();
    glColor4f(c.GetRedComponent(), c.GetGreenComponent(), c.GetBlueComponent(), c.GetAlphaComponent());
    //una llama
    glutSolidSphere(radius, 16, 16); 
    glPopMatrix();
    if (fireEmitter) fireEmitter->Render();
}

Solid* Enemy::Clone()
{
    return new Enemy(*this);
}

Enemy::~Enemy()
{
    delete fireEmitter;
}

