#pragma once
#include "Enemy.h"
#include "Player.h"
#include "Scene.h"
#include <vector>
#include <cstdlib> // rand
#include <ctime>

class EnemyManager {
private:
    std::vector<Enemy*> enemies;
    Player* player;
    float spawnInterval;       // tiempo entre spawns
    float timeSinceLastSpawn;  // contador interno

public:
    EnemyManager(Player* p, float interval = 1.0f)
        : player(p), spawnInterval(interval), timeSinceLastSpawn(0.0f)
    {
        srand(static_cast<unsigned int>(time(0))); // inicializa rand
    }

    ~EnemyManager() {
        for (Enemy* e : enemies)
            delete e;
        enemies.clear();
    }

    // Se llama desde Game::Update
    void Update(float dt, Scene* scene) {
        timeSinceLastSpawn += dt;

        if (timeSinceLastSpawn >= spawnInterval) {
            SpawnEnemy(scene);
            timeSinceLastSpawn = 0.0f;
        }
    }

private:
    void SpawnEnemy(Scene* scene) {
        // Elegir tipo según probabilidades
        int r = rand() % 100;
        EnemyType type;
        if (r < 50) type = EnemyType::MEDUSA;       // 0-49
        else if (r < 80) type = EnemyType::PULPO;   // 50-79
        else type = EnemyType::TIBURON;             // 80-99

        Enemy* e = new Enemy(type, player);

        // Posición: X fija (-9), Y aleatoria según tipo
        float y = 0.0f;
        switch (type) {
        case EnemyType::MEDUSA:   y = (rand() % 11 - 5) * 0.3f; break; // -1.5 a 1.5
        case EnemyType::PULPO:    y = (rand() % 9 - 4) * 0.4f;  break; // -1.6 a 1.6
        case EnemyType::TIBURON:  y = (rand() % 7 - 3) * 0.5f;  break; // -1.5 a 1.5
        }

        e->SetCoordinates(Vector3D(-9.0f, y, 0.0f));
        scene->AddGameObject(e);
        enemies.push_back(e);
    }
};