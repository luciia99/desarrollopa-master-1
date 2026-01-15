#include "EnemyEmitter.h"
#include <cstdlib>
#include <ctime>

EnemyEmitter::EnemyEmitter(
    Player* p,
    Scene* s,
    float interval,
    float x
)
    : player(p),
    scene(s),
    emissionInterval(interval),
    timeSinceLastEmission(0.0f),
    spawnX(x)
{
    srand(static_cast<unsigned int>(time(nullptr)));
}

EnemyEmitter::~EnemyEmitter()
{
    for (Enemy* e : enemies)
        delete e;
    enemies.clear();
}

void EnemyEmitter::Update(float dt)
{
    timeSinceLastEmission += dt;

    if (timeSinceLastEmission >= emissionInterval)
    {
        EmitEnemy();
        timeSinceLastEmission = 0.0f;
    }
}

void EnemyEmitter::EmitterEnem()
{
    int r = rand() % 100;
    EnemyType type;

    if (r < 50)       type = EnemyType::MEDUSA;
    else if (r < 80)  type = EnemyType::PULPO;
    else              type = EnemyType::TIBURON;

    Enemy* enemy = new Enemy(type, player);

    float y = 0.0f;
    switch (type)
    {
    case EnemyType::MEDUSA:
        y = (rand() % 11 - 5) * 0.3f;
        break;
    case EnemyType::PULPO:
        y = (rand() % 9 - 4) * 0.4f;
        break;
    case EnemyType::TIBURON:
        y = (rand() % 7 - 3) * 0.5f;
        break;
    }

    enemy->SetCoordinates(Vector3D(spawnX, y, 0.0f));

    scene->AddGameObject(enemy);
    enemies.push_back(enemy);
}