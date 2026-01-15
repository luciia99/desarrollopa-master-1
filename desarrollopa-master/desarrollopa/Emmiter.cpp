#include "Emmiter.h"
#include "EmmiterConfiguration.h"
#include "Solid.h"

Emmiter::Emmiter(const EmmiterConfiguration& cfg) : config(cfg){}

void Emmiter::EmitOnce()
{
    for (int i = 0; i < config.GetNumParticulas(); i++)
    {
        Particle p;
        p.obj = config.GetParticula()->Clone();
        p.obj->SetCoordinates(position);
        p.velocity = speed * config.GetParticleSpeed();
        p.life = config.GetParticleLife();

        particles.push_back(p);
    }
}

void Emmiter::Update(float dt, const Vector3D& gravity)
{
    // Actualizar partículas existentes
    for (auto it = particles.begin(); it != particles.end();){
        it->life -= dt;

        if (it->life <= 0.0f){
            delete it->obj;
            it = particles.erase(it);
        }else{
            Vector3D pos = it->obj->GetCoordinates();
            pos = pos + it->velocity * dt;
            it->obj->SetCoordinates(pos);
            ++it;
        }
    }
}

void Emmiter::Render()
{
    for (auto& p : particles) p.obj->Render();
}
