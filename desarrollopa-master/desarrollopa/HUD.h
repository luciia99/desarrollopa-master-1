#pragma once
#include "Text.h"
#include "Player.h"
#include "ScoreManager.h"
#include <string>

class HUD {
private:
    Text* textVidaPuntos;
    Text* textNivel;
    Text* textMensajeFinal;   // Texto de victoria/derrota
    Player* player;
    ScoreManager* scoreMgr;
    std::string nivelNombre;

public:
    HUD(Player* p, ScoreManager* sm, const std::string& nivel = "Nivel 1");

    void Render();

    void SetNivel(const std::string& nivel);
    void MostrarVictoria();
    void MostrarDerrota();

    ~HUD();
};