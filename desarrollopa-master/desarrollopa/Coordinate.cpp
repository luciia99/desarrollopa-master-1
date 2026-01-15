#include "Coordinate.h"
#include <ostream> 

ostream& operator<<(ostream& os, const Coordinate& coord) {
    os << "(" << coord.x << ", " << coord.y << ")";
    return os;
}