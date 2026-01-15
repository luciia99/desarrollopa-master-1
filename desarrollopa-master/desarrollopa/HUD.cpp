#include "HUD.h"
#include <GL/glut.h>
#include <cstdio>

HUD::HUD(Player* p, ScoreManager* sm, const std::string& nivel)
    : player(p), scoreMgr(sm), nivelNombre(nivel)
{
    // Vida y puntos
    textVidaPuntos = new Text("", GLUT_BITMAP_HELVETICA_18);
    textVidaPuntos->SetColor(Color(1, 1, 1, 1));
    textVidaPuntos->SetCoordinates(Vector3D(-9.5f, 5.5f, 0.0f));

    // Nivel
    textNivel = new Text(nivelNombre, GLUT_BITMAP_HELVETICA_18);
    textNivel->SetColor(Color(1, 1, 0, 1));
    textNivel->SetCoordinates(Vector3D(0.0f, 5.5f, 0.0f));

    // Mensaje final (inicialmente vacío)
    textMensajeFinal = new Text("", GLUT_BITMAP_HELVETICA_18);
    textMensajeFinal->SetColor(Color(1, 0, 0, 1)); // rojo por defecto
    textMensajeFinal->SetCoordinates(Vector3D(0.0f, 0.0f, 0.0f)); // centro pantalla
}

void HUD::Render() {
    // Vida y puntos
    if (textVidaPuntos) {
        char buf[128];
        sprintf_s(buf, "Vida: %d  Puntos: %d",
            player ? player->GetHealth() : 0,
            scoreMgr ? scoreMgr->GetScore() : 0);
        textVidaPuntos->SetText(buf);
        textVidaPuntos->Render();
    }

    // Nivel
    if (textNivel)
        textNivel->Render();

    // Mensaje final (si lo hay)
    if (textMensajeFinal && textMensajeFinal->GetText() != "")
        textMensajeFinal->Render();
}

void HUD::SetNivel(const std::string& nivel) {
    nivelNombre = nivel;
    if (textNivel)
        textNivel->SetText(nivelNombre);
}

void HUD::MostrarVictoria() {
    if (textMensajeFinal) {
        textMensajeFinal->SetText("¡Victoria!");
        textMensajeFinal->SetColor(Color(0, 1, 0, 1)); // verde
    }
}

void HUD::MostrarDerrota() {
    if (textMensajeFinal) {
        textMensajeFinal->SetText("¡Derrota!");
        textMensajeFinal->SetColor(Color(1, 0, 0, 1)); // rojo
    }
}

HUD::~HUD() {
    delete textVidaPuntos;
    delete textNivel;
    delete textMensajeFinal;
}