#include "EnemyManager.h"
#include <cstdlib>
#include <ctime>
#include <cmath>

EnemyManager::EnemyManager(Player* p, float interval)
    : player(p), spawnInterval(interval), timeSinceLastSpawn(0.0f) {
    srand(static_cast<unsigned int>(time(nullptr))); // inicializar generador de números aleatorios
}

EnemyManager::~EnemyManager() {
    for (Enemy* e : enemies)
        delete e;
    enemies.clear(); // liberar memoria de todos los enemigos
}

void EnemyManager::Update(float dt, Scene* scene) {
    timeSinceLastSpawn += dt;

    if (timeSinceLastSpawn >= spawnInterval) {
        Enemy* enemy = new Enemy(player);
        // asignar posición vertical aleatoria dentro del rango
        float y = (rand() % 11 - 5) * 0.4f;
        enemy->SetCoordinates(Vector3D(-9.0f, y, 0.0f));

        enemies.push_back(enemy);
        if (scene) scene->AddGameObject(enemy); // añadir enemigo a la escena si existe

        timeSinceLastSpawn = 0.0f; // reiniciar temporizador de aparición
    }
}

void EnemyManager::CheckBubbleCollisions(Emmiter* bubbleEmitter, ScoreManager* scoreMgr)
{
    if (!bubbleEmitter) return; // salir si el emisor no es válido

    const auto& particles = bubbleEmitter->GetParticles();

    for (Enemy* enemy : enemies) {
        if (!enemy || !enemy->IsActive())
            continue; // ignorar enemigos nulos o inactivos

        Vector3D ePos = enemy->GetCoordinates();
        float eRadius = enemy->GetRadius();

        for (const auto& p : particles) {
            Vector3D pPos = p.obj->GetCoordinates();
            Vector3D diff = pPos - ePos;

            float dist2 = diff * diff;
            float colDist = eRadius + 0.15f;

            if (dist2 < colDist * colDist) {
                enemy->Damage(1); // aplicar daño al enemigo
                enemy->Deactivate(); // desactivar enemigo tras colisión

                if (scoreMgr)
                    scoreMgr->Add(1); // incrementar puntuación

                break; // detener búsqueda de colisiones para este enemigo
            }
        }
    }
}