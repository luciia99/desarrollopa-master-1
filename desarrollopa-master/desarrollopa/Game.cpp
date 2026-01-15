#include "Game.h"
#include <iostream>
#include "Model.h"
#include "ModelLoader.h"

using namespace std;

Game::Game()
{
    display = new Display();
    sceneManager = new SceneManager();
    scoreManager = new ScoreManager();
    player = nullptr;
    enemyManager = nullptr; // inicializar puntero de enemigos
    hud = nullptr;
    hudText = nullptr;

    gameOver = false;
    victory = false;

    // registrar tiempo inicial en milisegundos
    initialMilliseconds = duration_cast<milliseconds>(
        system_clock::now().time_since_epoch()
    );
    lastUpdatedTime = duration_cast<milliseconds>(
        system_clock::now().time_since_epoch()
    ).count();

    // inicializar acumuladores de jugabilidad
    healthAccumulator = 0.0f;
    scoreAccumulator = 0.0f;
}

void Game::Init()
{
    cout << "[GAME] Init..." << endl;

    ModelLoader loader; // gestor de modelos OBJ

    // --- Nivel 1 ---
    Scene* scene1 = new Scene();

    // crear jugador y establecer posición inicial
    player = new Player();
    player->SetCoordinates(Vector3D(9.0f, 0.0f, 0.0f));

    // cargar modelo y asignar color
    loader.LoadModel("models/waterdrop.obj");
    Model waterdropModel = loader.GetModel();
    waterdropModel.SetColor(Color(0.3f, 0.6f, 1.0f, 1.0f));

    // asociar modelo al jugador
    player->SetWaterdrop(waterdropModel);

    // agregar jugador a la escena
    scene1->AddGameObject(player);

    // inicializar EnemyManager con spawn normal
    enemyManager = new EnemyManager(player, 2.0f);

    // crear nivel 1 y agregarlo al SceneManager
    Level* level1 = new Level("Nivel 1", scene1);
    sceneManager->AddLevel(level1);

    // --- Nivel 2 ---
    Scene* scene2 = new Scene();
    scene2->AddGameObject(player); // reutilizar jugador en nivel 2

    // crear nivel 2 (enemigos más rápidos), sin asignar EnemyManager aún
    Level* level2 = new Level("Nivel 2", scene2);
    sceneManager->AddLevel(level2);

    // --- HUD ---
    hud = new HUD(player, scoreManager, level1->GetName());

    cout << "[GAME] Init complete." << endl;
}

void Game::Render()
{
    Level* lvl = sceneManager->GetCurrentLevel();
    if (lvl && lvl->GetScene())
    {
        lvl->GetScene()->Render(); // renderizar escena actual
    }

    if (hud)
        hud->Render(); // renderizar HUD
}

void Game::Update(const float& time)
{
    if (gameOver || victory) return;

    // calcular delta time (dt) desde la última actualización
    milliseconds currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
    float dt = (currentTime.count() - lastUpdatedTime) / 1000.0f;

    // actualizar escena (jugador, burbujas, objetos)
    sceneManager->UpdateCurrent(dt);

    // revisar colisiones entre burbujas del jugador y enemigos
    if (enemyManager && player)
        enemyManager->CheckBubbleCollisions(player->GetBubbleEmitter(), scoreManager);

    // actualizar enemigos (movimiento y spawn)
    if (enemyManager)
        enemyManager->Update(dt, sceneManager->GetCurrent()->GetScene());

    // revisar colisiones de fuego enemigo con jugador
    if (enemyManager && player) {
        for (Enemy* e : enemyManager->GetEnemies()) {
            Emmiter* fire = e->GetFireEmitter();
            if (!fire) continue;

            const auto& particles = fire->GetParticles();
            Vector3D pPos = player->GetCoordinates();

            for (const auto& part : particles) {
                Vector3D diff = part.obj->GetCoordinates() - pPos;
                if ((diff * diff) < 0.3f * 0.3f) {
                    player->Damage(1); // aplicar daño al jugador
                    break; // detener revisión tras colisión
                }
            }
        }
    }

    // verificar condición de derrota
    if (player && player->GetHealth() <= 0 && !gameOver) {
        gameOver = true;
        cout << "[GAME] Derrota: vida del jugador llegó a 0" << endl;
        if (hud) hud->MostrarDerrota();
    }

    // verificar condición de victoria o cambio de nivel
    int nivelActual = sceneManager->GetCurrentIndex();
    int scoreObjetivo = (nivelActual == 0) ? 10 : 20;

    if (scoreManager && scoreManager->GetScore() >= scoreObjetivo && !victory) {
        if (nivelActual + 1 < (int)sceneManager->Count()) {
            // pasar al siguiente nivel
            sceneManager->NextLevel();
            player->SetHealth(3);
            scoreManager->Reset();

            // reemplazar EnemyManager para nuevo nivel
            delete enemyManager;
            enemyManager = new EnemyManager(player, 1.0f); // nivel 2 con spawn más rápido

            // actualizar HUD con nombre de nivel
            if (hud)
                hud->SetNivel(sceneManager->GetCurrentLevel()->GetName());

            cout << "[GAME] Pasamos a " << sceneManager->GetCurrentLevel()->GetName() << endl;
        }
        else {
            // no hay más niveles, victoria final
            victory = true;
            cout << "[GAME] Victoria alcanzada!" << endl;
            if (hud) hud->MostrarVictoria();
        }
    }

    // actualizar HUD (vida, puntos, nivel)
    if (hud)
        hud->Render();

    lastUpdatedTime = currentTime.count(); // guardar tiempo de actualización
}

void Game::ProcessKeyPressed(unsigned char key, int px, int py)
{
    if (!player || gameOver || victory) return;

    // mover jugador según tecla presionada
    if (key == 'w' || key == 'W') player->MoveUp();
    if (key == 's' || key == 'S') player->MoveDown();
}

void Game::ProcessMouseClicked(int button, int state, int x, int y)
{
    if (!player || gameOver || victory) return;

    // disparar burbuja al hacer clic izquierdo
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        player->Shoot(x, y);
    }
}

void Player::SetWaterdrop(const Model& m) {
    waterdrop = m; // asignar modelo al jugador
}