#include <GL/glut.h> 
#include "Camera.h"

// Implementación de la cámara utilizando transformaciones OpenGL
void Camera::Render()
{
    glLoadIdentity();
    gluLookAt(
        0.0, 0.0, 15.0,   // posición cámara
        0.0, 0.0, 0.0,    // mira al centro
        0.0, 1.0, 0.0     // vector up
    );

}

void Camera::Update(const float& time)
{
    Solid::Update(time, Vector3D(0.0f, 0.0f, 0.0f));
}