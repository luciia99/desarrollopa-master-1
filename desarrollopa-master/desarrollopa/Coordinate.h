#pragma once
#include <iosfwd>

using namespace std;

class Coordinate
{
private:
	float x;
	float y;

public:
	Coordinate(float x = 0.0f, float y = 0.0f) : x(x), y(y) {}

	friend ostream& operator<<(ostream& os, const Coordinate& coord);
};



