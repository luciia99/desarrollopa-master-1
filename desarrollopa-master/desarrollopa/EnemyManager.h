#pragma once
#include <vector>
#include "Enemy.h"
#include "Scene.h"
#include "Emmiter.h"
#include "ScoreManager.h"

class EnemyManager {
private:
    std::vector<Enemy*> enemies;
    Player* player;

    float spawnInterval;
    float timeSinceLastSpawn;

public:
    EnemyManager(Player* p, float interval = 4.0f);
    ~EnemyManager();

    void Update(float dt, Scene* scene);
    void CheckBubbleCollisions(Emmiter* bubbleEmitter, ScoreManager* scoreMgr);
    const vector<Enemy*>& GetEnemies() const { return enemies; }

};
