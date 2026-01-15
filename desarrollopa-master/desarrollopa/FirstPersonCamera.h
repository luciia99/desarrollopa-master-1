#pragma once
#include "Camera.h"
#define _USE_MATH_DEFINES
#include <math.h>
#define degToRad(angleInDegrees) ((angleInDegrees) * M_PI / 180.0)
#define radToDeg(angleInRadians) ((angleInRadians) * 180.0 / M_PI)

class FirstPersonCamera : public Camera {

private:
	//posiciones ratón
    int mouseX;
    int mouseY;

	//cálculo vector de velocidad
    Vector3D calcSpeedVector();

	//velocidad cámara
    float cameraStep;

    //movimiento
    bool moveForward = false;
    bool moveBackward = false;

public:
    FirstPersonCamera(Vector3D positionArgument = Vector3D()) : Camera(positionArgument), mouseX(-1), mouseY(-1), cameraStep(0.25) {};

    //métodos necesarios para la cámara en primera persona (la cámara se mueve con el jugador)
    void ProcessKeyPressed(unsigned char key, int px, int py);
    void ProcessMouseMovement(int x, int y);

    void Update(const float& time);
    void Render();

	//getters y setters 
    inline float GetMouseX() const { return this->mouseX; }
    inline void SetMouseX(const float& mouseXToSet) { this->mouseX = mouseXToSet; }

    inline float GetMouseY() const { return this->mouseY; }
    inline void SetMouseY(const float& mouseYToSet) { this->mouseY = mouseYToSet; }

};