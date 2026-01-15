#pragma once
#include "Vector3D.h"
#include "Color.h"

class Solid
{
private:
    Vector3D coordinates;
    Vector3D orientation;
    Color color;
    Vector3D orientationSpeed;
    Vector3D Speed;
	bool isAffectedByGravity;
public:
    Solid()
        : coordinates(0.0f, 0.0f, 0.0f),
        orientation(0.0f, 0.0f, 0.0f),
        color(Color()),           // constructor por defecto de Color
        orientationSpeed(0.0f, 0.0f, 0.0f),
        Speed(0.0f, 0.0f, 0.0f),
        isAffectedByGravity(false)
    {
    }
    // Getters
    Vector3D GetCoordinates() const { return coordinates; }
    Vector3D GetOrientation() const { return orientation; }
    Color GetColor() const { return color; }
    Vector3D GetOrientationSpeed() const { return orientationSpeed; }
    Vector3D GetSpeed() const { return Speed; }

    // Setters
    void SetCoordinates(Vector3D pos) { this->coordinates = pos; }
    void SetOrientation(Vector3D orient) { this->orientation = orient; }
	//cambiamos a virtual para poder sobreescribir en Model
    virtual void SetColor(Color c) { this->color = c; }
    void SetOrientationSpeed(Vector3D orientSpeed) { this->orientationSpeed = orientSpeed; }
    void SetSpeed(Vector3D speed) { this->Speed = speed; }
    void SetAffectedByGravity(bool isAffectedByGravity) { this->isAffectedByGravity = isAffectedByGravity; }

    // Método virtual puro
    virtual void Render() = 0;

    virtual void Update(const float& time, const Vector3D& gravity);

    virtual Solid* Clone() = 0;

	virtual ~Solid() {}
};

