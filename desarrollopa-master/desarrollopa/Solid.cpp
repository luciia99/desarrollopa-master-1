#include "Solid.h"

void Solid::Update(const float& time, const Vector3D& gravity) {
    //Rotación
    orientation = orientation + (orientationSpeed * time);
    //Movimiento espacial de los elementos
    coordinates = coordinates + (Speed * time);

    if (isAffectedByGravity) {
        Speed = Speed + (gravity * time);
    }
}