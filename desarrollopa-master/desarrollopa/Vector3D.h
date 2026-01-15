#pragma once
#include <cmath>

template<class S>
class Vector3Dx
{
private:
    S x, y, z;
public:
    Vector3Dx(S x = 0, S y = 0, S z = 0) :x(x), y(y), z(z) {}

    inline S GetX() const { return x; }
    inline S GetY() const { return y; }
    inline S GetZ() const { return z; }
    inline void SetX(S d) { x = d; }
    inline void SetY(S d) { y = d; }
    inline void SetZ(S d) { z = d; }

    Vector3Dx<S> operator-(Vector3Dx<S> v) {
        return Vector3Dx<S>(this->GetX() - v.GetX(), this->GetY() - v.GetY(), this->GetZ() - v.GetZ());
    }

    Vector3Dx<S> operator+(const Vector3Dx<S>& v) const {
        return Vector3Dx<S>(this->GetX() + v.GetX(), this->GetY() + v.GetY(), this->GetZ() + v.GetZ());
    }

    Vector3Dx<S> operator*(S s) {
        return Vector3Dx<S>(this->GetX() * s, this->GetY() * s, this->GetZ() * s);
    }

    Vector3Dx<S> operator/(S s) {
        return Vector3Dx<S>(this->GetX() / s, this->GetY() / s, this->GetZ() / s);
    }

    S operator*(Vector3Dx<S> v) {
        return this->GetX() * v.GetX() + this->GetY() * v.GetY() + this->GetZ() * v.GetZ();
    }

    // Añadir esta sobrecarga para permitir multiplicar un Vector3Dx<S> constante por un escalar
    Vector3Dx<S> operator*(S s) const {
        return Vector3Dx<S>(this->GetX() * s, this->GetY() * s, this->GetZ() * s);
    }
};

typedef Vector3Dx<float>  Vector3D;
typedef Vector3Dx<double> Vector3Dd;
typedef Vector3Dx<int>    Vector3Di;
