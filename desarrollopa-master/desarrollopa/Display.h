#pragma once
#include <iostream>
#include "Solid.h"
#include "Cuboid.h"

using namespace std;

class Display : public Solid
{
private:

	Cuboid segmentA;
	Cuboid segmentB;
	Cuboid segmentC;
	Cuboid segmentD;
	Cuboid segmentE;
	Cuboid segmentF;
	Cuboid segmentG;

public:
	Display()
	{
		//Posicion inicial del display
		SetCoordinates(Vector3D(0.0, 0.0, -8.0));
		SetOrientation(Vector3D(0.0f, 0.0f, 90.0f));

		//obtener la posición actual del Display (que ahora hereda de Solid) y almacenarla en una variable llamada basePos
		Vector3D basePos = GetCoordinates();
		Vector3D baseOrient = GetOrientation();

		segmentA.SetCoordinates(basePos + Vector3D(0.0, 2.0, 0.0));
		segmentA.SetOrientation(baseOrient);

		segmentB.SetCoordinates(basePos + Vector3D(1.0, 1.0, 0.0));

		segmentC.SetCoordinates(basePos + Vector3D(1.0, -1.0, 0.0));

		segmentD.SetCoordinates(basePos + Vector3D(0.0, -2.0, 0.0));
		segmentD.SetOrientation(baseOrient);

		segmentE.SetCoordinates(basePos + Vector3D(-1.0, -1.0, 0.0));

		segmentF.SetCoordinates(basePos + Vector3D(-1.0, 1.0, 0.0));

		segmentG.SetCoordinates(basePos + Vector3D(0.0, 0.0, 0.0));
		segmentG.SetOrientation(baseOrient);

	}
	void Render() 
	{
		segmentA.Render();
		segmentB.Render();
		segmentC.Render();
		segmentD.Render();
		segmentE.Render();
		segmentF.Render();
		segmentG.Render();
	}

	void Update(const float& time, const Vector3D& gravity) {}

	Solid* Clone() 
	{
		return new Display(*this);
	}

	inline Cuboid GetSegmentA() { return segmentA; }
	inline Cuboid GetSegmentB() { return segmentB; }
	inline Cuboid GetSegmentC() { return segmentC; }
	inline Cuboid GetSegmentD() { return segmentD; }
	inline Cuboid GetSegmentE() { return segmentE; }
	inline Cuboid GetSegmentF() { return segmentF; }
	inline Cuboid GetSegmentG() { return segmentG; }

	void Init();
	void ProcessKeyPressed(unsigned char key, int px, int py);
};

