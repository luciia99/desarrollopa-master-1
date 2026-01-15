#pragma once
#include "Text.h"
#include "Player.h"
#include "ScoreManager.h"

class HUD {
private:
    Text* text;
    Player* player;
    ScoreManager* scoreMgr;
public:
    HUD(Text* t, Player* p, ScoreManager* sm) : text(t), player(p), scoreMgr(sm) {}
    void Render() {
        if (!text) return;

        char buf[128];
        sprintf_s(buf, "Vida: %d  Puntos: %d",
            player ? player->GetHealth() : 0,
            scoreMgr ? scoreMgr->GetScore() : 0);

        text->SetText(buf);
        text->Render();
    }
};
