#include "Coordinate.h"
#include <ostream> // Añadir esta línea para incluir la definición de ostream

ostream& operator<<(ostream& os, const Coordinate& coord) {
    os << "(" << coord.x << ", " << coord.y << ")";
    return os;
}