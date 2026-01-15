#include "Text.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>


void Text::Render()
{
    // Guardar estado de la matriz y desplazamiento
    glPushMatrix();

    // Color
    Color c = GetColor();
    glColor4f(c.GetRedComponent(), c.GetGreenComponent(), c.GetBlueComponent(), c.GetAlphaComponent());

    // Aplicar transformaciones según las coordenadas del Solid
    glTranslatef(GetCoordinates().GetX(),
        GetCoordinates().GetY(),
        GetCoordinates().GetZ());

    // Posición de inicio del texto
    glRasterPos3d(0.0, 0.0, 0.0);

    // Dibuja cada letra
    for (char c : text) {
        glutBitmapCharacter(font, c);
    }

    glPopMatrix();
}
