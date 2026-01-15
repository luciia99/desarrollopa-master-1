#include <GL/glut.h> // Añade esta línea al inicio del archivo para definir glRotatef
#include "Camera.h"

// Implementación de la cámara utilizando transformaciones OpenGL
void Camera::Render()
{
    //Traslación
    glTranslatef(-position.GetX(), -position.GetY(), -position.GetZ());

    //Rotaciones
    glRotatef(rotation.GetX(), 1.0, 0.0, 0.0);
    glRotatef(rotation.GetY(), 0.0, 1.0, 0.0);
    glRotatef(rotation.GetZ(), 0.0, 0.0, 1.0);

}

void Camera::Update(const float& time)
{
    Solid::Update(time, Vector3D(0.0f, 0.0f, 0.0f));
}