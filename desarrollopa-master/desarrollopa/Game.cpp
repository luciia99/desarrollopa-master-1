#include "Game.h"
#include <iostream>
#include "Enemy.h"
#include "EnemyManager.h"

using namespace std;

Game::Game()
{
    display = new Display();
    sceneManager = new SceneManager();
    scoreManager = new ScoreManager();
    player = nullptr;
    enemyManager = nullptr; // inicializamos el miembro
    hud = nullptr;
    hudText = nullptr;

    gameOver = false;
    victory = false;

    initialMilliseconds = duration_cast<milliseconds>(
        system_clock::now().time_since_epoch()
    );
    lastUpdatedTime = duration_cast<milliseconds>( system_clock::now().time_since_epoch()).count();
    // Inicializar acumuladores de jugabilidad
    healthAccumulator = 0.0f;
    scoreAccumulator = 0.0f;
}

void Game::Init()
{
    cout << "[GAME] Init..." << endl;

    // Crear escena principal
    Scene* mainScene = new Scene();

    // Crear jugador
    player = new Player();
    player->SetCoordinates(Vector3D(9.0f, 0.0f, 0.0f)); // lado derecho
    player->SetColor(Color(1.0f, 1.0f, 0.0f, 1.0f));     // amarillo
    mainScene->AddGameObject(player);

    // Crear gestor de enemigos y asignarle el jugador
    enemyManager = new EnemyManager(player, 2.0f); // tiempo de spawn

    // Crear HUD
    hud = new HUD(nullptr, player, scoreManager);

    // Crear nivel y añadirlo al gestor de escenas
    Level* level1 = new Level("Nivel 1", mainScene);
    sceneManager->AddLevel(level1);

    cout << "[GAME] Init complete." << endl;
}

void Game::Render()
{
    Level* lvl = sceneManager->GetCurrentLevel();
    if (lvl && lvl->GetScene())
    {
        lvl->GetScene()->Render();
    }

    if (hud)
        hud->Render();
}

void Game::Update(const float& time)
{
    // Si el juego ya terminó, no procesamos más actualizaciones
    if (gameOver || victory) return;

    milliseconds currentTime = duration_cast<milliseconds>(
        system_clock::now().time_since_epoch()
    );

    // dt en segundos desde la última actualización
    float dt = (currentTime.count() - lastUpdatedTime) / 1000.0f;

    // Actualizamos la escena
    sceneManager->UpdateCurrent(dt);

    // Actualizar EnemyManager con dt real
    if (enemyManager)
        enemyManager->Update(dt, sceneManager->GetCurrent()->GetScene());

    lastUpdatedTime = currentTime.count();

    //gestionamos las colisiones del fuego con el jugador
    if (enemyManager && player){
        for (Enemy* e : enemyManager->GetEnemies()){
            Emmiter* fire = e->GetFireEmitter();
            if (!fire) continue;

            const auto& particles = fire->GetParticles();
            Vector3D pPos = player->GetCoordinates();

            for (const auto& part : particles){
                Vector3D diff = part.obj->GetCoordinates() - pPos;
                float dist2 = diff * diff;

                if (dist2 < 0.3f * 0.3f){
                    player->Damage(1);
                    break;
                }
            }
        }
    }

    // Actualizar acumuladores
    healthAccumulator += dt;
    scoreAccumulator += dt;

    // Condición derrota
    if (player && player->GetHealth() <= 0 && !gameOver)
    {
        gameOver = true;
        cout << "[GAME] Defeat: player health reached zero." << endl;
    }

    // Condición victoria
    if (scoreManager && scoreManager->GetScore() >= 10 && !victory)
    {
        victory = true;
        cout << "[GAME] Victory achieved!" << endl;
    }
}

void Game::ProcessKeyPressed(unsigned char key, int px, int py)
{
    if (!player || gameOver || victory) return;

    if (key == 'w' || key == 'W') player->MoveUp();
    if (key == 's' || key == 'S') player->MoveDown();
}


void Game::ProcessMouseClicked(int button, int state, int x, int y)
{
    if (!player || gameOver || victory) return;

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        player->Shoot(x, y);
    }
}