#pragma once
#include "Enemy.h"
#include "Player.h"
#include "Scene.h"
#include <vector>
#include <cstdlib>
#include <ctime>

class EnemyManager {
private:
    // Enemigos emitidos (como partículas)
    std::vector<Enemy*> emittedEnemies;

    Player* player;

    // Configuración del emisor
    float emissionInterval;        // tiempo entre emisiones
    float timeSinceLastEmission;   // acumulador de tiempo

    // Posición base del emisor
    float spawnX;

public:
    EnemyManager(Player* p, float interval = 1.0f, float x = -9.0f)
        : player(p),
        emissionInterval(interval),
        timeSinceLastEmission(0.0f),
        spawnX(x)
    {
        srand(static_cast<unsigned int>(time(nullptr)));
    }

    ~EnemyManager() {
        for (Enemy* e : emittedEnemies)
            delete e;
        emittedEnemies.clear();
    }

    // Se llama desde Game::Update
    void Update(float dt, Scene* scene) {
        timeSinceLastEmission += dt;

        if (timeSinceLastEmission >= emissionInterval) {
            EmitEnemy(scene);
            timeSinceLastEmission = 0.0f;
        }
    }

private:
    void EmitEnemy(Scene* scene) {
        // Probabilidades: Medusa > Pulpo > Tiburón
        int r = rand() % 100;
        EnemyType type;

        if (r < 50)       type = EnemyType::MEDUSA;
        else if (r < 80)  type = EnemyType::PULPO;
        else              type = EnemyType::TIBURON;

        Enemy* enemy = new Enemy(type, player);

        // Y aleatoria, X fija (emisor lateral)
        float y = 0.0f;
        switch (type) {
        case EnemyType::MEDUSA:  y = (rand() % 11 - 5) * 0.3f; break;
        case EnemyType::PULPO:   y = (rand() % 9 - 4) * 0.4f; break;
        case EnemyType::TIBURON: y = (rand() % 7 - 3) * 0.5f; break;
        }

        enemy->SetCoordinates(Vector3D(spawnX, y, 0.0f));

        scene->AddGameObject(enemy);
        emittedEnemies.push_back(enemy);
    }
};