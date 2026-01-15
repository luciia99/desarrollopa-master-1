#pragma once

#include "Display.h"
#include "Scene.h"
#include "Player.h"
#include "HUD.h"
#include "ScoreManager.h"
#include "SceneManager.h"
#include "EnemyManager.h"
#include <chrono>

using namespace chrono;

class Game
{
private:
    Display* display;

    // Gestión de escenas y niveles
    SceneManager* sceneManager;

    // Jugador
    Player* player;

    // HUD
    HUD* hud;
    Text* hudText;
    ScoreManager* scoreManager;
    EnemyManager* enemyManager;

    // Estado del juego
    bool gameOver;
    bool victory;

    // Control de tiempo
    const double TIME_INCREMENT = 0.4;
    const long UPDATE_PERIOD = 10;
    milliseconds initialMilliseconds;
    long long lastUpdatedTime;

    // Acumuladores para la jugabilidad mínima
    float healthAccumulator;
    float scoreAccumulator;
    const float HEALTH_DECREASE_INTERVAL = 1.0f; // cada 1 segundo -> -1 vida
    const float SCORE_INCREASE_INTERVAL = 0.5f;  // cada 0.5s -> +1 punto

public:
    Game();
    void Init();
    void Render();
    void Update(const float& time);
    void ProcessKeyPressed(unsigned char key, int px, int py);
    void ProcessMouseMovement(int x, int y);
    void ProcessMouseClicked(int button, int state, int x, int y);
};

