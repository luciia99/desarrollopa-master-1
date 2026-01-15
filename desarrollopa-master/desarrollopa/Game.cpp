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

    ModelLoader loader; // <-- Añadida línea para definir 'loader'

    // --- Nivel 1 ---
    Scene* scene1 = new Scene();

    // Crear jugador
    player = new Player();
    player->SetCoordinates(Vector3D(9.0f, 0.0f, 0.0f));
    // Cargar modelo OBJ y asignarlo
    loader.LoadModel("models/waterdrop.obj");

    // 4. Obtener el modelo generado
    Model waterdropModel = loader.GetModel();
    waterdropModel.SetColor(Color(0.3f, 0.6f, 1.0f, 1.0f));

    // 5. Asignar al jugador
    player->SetWaterdrop(waterdropModel);
    // Agregar jugador a la escena
    scene1->AddGameObject(player);

    // EnemyManager para nivel 1 (spawn normal)
    enemyManager = new EnemyManager(player, 2.0f);

    // Crear nivel 1
    Level* level1 = new Level("Nivel 1", scene1);
    sceneManager->AddLevel(level1);

    // --- Nivel 2 ---
    Scene* scene2 = new Scene();

    // Mismo jugador en nivel 2
    scene2->AddGameObject(player);

    // Creamos nivel 2 (enemigos más rápidos) pero no asignamos todavía enemyManager
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
        lvl->GetScene()->Render();
    }

    if (hud)
        hud->Render();
}

void Game::Update(const float& time)
{
    if (gameOver || victory) return;

    // Calcular dt
    milliseconds currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
    float dt = (currentTime.count() - lastUpdatedTime) / 1000.0f;

    // 1?? Actualizar la escena (jugador, burbujas)
    sceneManager->UpdateCurrent(dt);

    // 2?? Revisar colisiones burbujas ? enemigos
    if (enemyManager && player)
        enemyManager->CheckBubbleCollisions(player->GetBubbleEmitter(), scoreManager);

    // 3?? Actualizar enemigos (movimiento y spawn)
    if (enemyManager)
        enemyManager->Update(dt, sceneManager->GetCurrent()->GetScene());

    // 4?? Colisiones fuego ? jugador
    if (enemyManager && player) {
        for (Enemy* e : enemyManager->GetEnemies()) {
            Emmiter* fire = e->GetFireEmitter();
            if (!fire) continue;

            const auto& particles = fire->GetParticles();
            Vector3D pPos = player->GetCoordinates();

            for (const auto& part : particles) {
                Vector3D diff = part.obj->GetCoordinates() - pPos;
                if ((diff * diff) < 0.3f * 0.3f) {
                    player->Damage(1);
                    break;
                }
            }
        }
    }

    // 5?? Condición derrota
    if (player && player->GetHealth() <= 0 && !gameOver) {
        gameOver = true;
        cout << "[GAME] Derrota: vida del jugador llegó a 0" << endl;
        if (hud) hud->MostrarDerrota();
    }

    // 6?? Condición victoria / cambio de nivel
    int nivelActual = sceneManager->GetCurrentIndex();
    int scoreObjetivo = (nivelActual == 0) ? 10 : 20;

    if (scoreManager && scoreManager->GetScore() >= scoreObjetivo && !victory) {
        if (nivelActual + 1 < (int)sceneManager->Count()) {
            // Pasar al siguiente nivel
            sceneManager->NextLevel();
            player->SetHealth(3);             
            scoreManager->Reset();

            // Reemplazar enemyManager para el nuevo nivel
            delete enemyManager;
            enemyManager = new EnemyManager(player, 1.0f); // nivel 2 más rápido

            // Actualizar HUD con nombre de nivel
            if (hud)
                hud->SetNivel(sceneManager->GetCurrentLevel()->GetName());

            cout << "[GAME] Pasamos a " << sceneManager->GetCurrentLevel()->GetName() << endl;
        }
        else {
            // No hay más niveles ? victoria final
            victory = true;
            cout << "[GAME] Victoria alcanzada!" << endl;
            if (hud) hud->MostrarVictoria();
        }
    }

    // 7?? Actualizar HUD (vida, puntos y nivel)
    if (hud)
        hud->Render();

    lastUpdatedTime = currentTime.count();
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

void Player::SetWaterdrop(const Model& m) {
    waterdrop = m;
}