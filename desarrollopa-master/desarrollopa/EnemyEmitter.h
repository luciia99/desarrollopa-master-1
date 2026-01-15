#pragma once
#include "Emmiter.h"
#include "Enemy.h"
#include "Player.h"
#include "Scene.h"

class EnemyEmitter : public Emmiter {
private:
    Player* player;
    Scene* scene;
    float spawnX;

public:
    EnemyEmitter(
        EmmiterConfiguration& config,
        Player* p,
        Scene* s,
        float x = -9.0f
    );

    void Update(const float& time) override;
};