#include "Display.h"

void Display::Init() {}

void Display::ProcessKeyPressed(unsigned char key, int px, int py)
{
	cout << "[DISPLAY] Key:" << key << endl;
	switch (key)
	{
	case '1':
		this->segmentA.SetColor(Color(this->segmentA.GetColor().GetRedComponent(), this->segmentA.GetColor().GetGreenComponent(), this->segmentA.GetColor().GetBlueComponent(), 0.1f));
		this->segmentB.SetColor(Color(this->segmentB.GetColor().GetRedComponent(), this->segmentB.GetColor().GetGreenComponent(), this->segmentB.GetColor().GetBlueComponent(), 1.0f));
		this->segmentC.SetColor(Color(this->segmentC.GetColor().GetRedComponent(), this->segmentC.GetColor().GetGreenComponent(), this->segmentC.GetColor().GetBlueComponent(), 1.0f));
		this->segmentD.SetColor(Color(this->segmentD.GetColor().GetRedComponent(), this->segmentD.GetColor().GetGreenComponent(), this->segmentD.GetColor().GetBlueComponent(), 0.1f));
		this->segmentE.SetColor(Color(this->segmentE.GetColor().GetRedComponent(), this->segmentE.GetColor().GetGreenComponent(), this->segmentE.GetColor().GetBlueComponent(), 0.1f));
		this->segmentF.SetColor(Color(this->segmentF.GetColor().GetRedComponent(), this->segmentF.GetColor().GetGreenComponent(), this->segmentF.GetColor().GetBlueComponent(), 0.1f));
		this->segmentG.SetColor(Color(this->segmentG.GetColor().GetRedComponent(), this->segmentG.GetColor().GetGreenComponent(), this->segmentG.GetColor().GetBlueComponent(), 0.1f));

		break;
	case '2':
		this->segmentA.SetColor(Color(this->segmentA.GetColor().GetRedComponent(), this->segmentA.GetColor().GetGreenComponent(), this->segmentA.GetColor().GetBlueComponent(), 1.0f));
		this->segmentB.SetColor(Color(this->segmentB.GetColor().GetRedComponent(), this->segmentB.GetColor().GetGreenComponent(), this->segmentB.GetColor().GetBlueComponent(), 1.0f));
		this->segmentC.SetColor(Color(this->segmentC.GetColor().GetRedComponent(), this->segmentC.GetColor().GetGreenComponent(), this->segmentC.GetColor().GetBlueComponent(), 0.1f));
		this->segmentD.SetColor(Color(this->segmentD.GetColor().GetRedComponent(), this->segmentD.GetColor().GetGreenComponent(), this->segmentD.GetColor().GetBlueComponent(), 1.0f));
		this->segmentE.SetColor(Color(this->segmentE.GetColor().GetRedComponent(), this->segmentE.GetColor().GetGreenComponent(), this->segmentE.GetColor().GetBlueComponent(), 1.0f));
		this->segmentF.SetColor(Color(this->segmentF.GetColor().GetRedComponent(), this->segmentF.GetColor().GetGreenComponent(), this->segmentF.GetColor().GetBlueComponent(), 0.1f));
		this->segmentG.SetColor(Color(this->segmentG.GetColor().GetRedComponent(), this->segmentG.GetColor().GetGreenComponent(), this->segmentG.GetColor().GetBlueComponent(), 1.0f));
		break;
	case '3':
		this->segmentA.SetColor(Color(this->segmentA.GetColor().GetRedComponent(), this->segmentA.GetColor().GetGreenComponent(), this->segmentA.GetColor().GetBlueComponent(), 1.0f));
		this->segmentB.SetColor(Color(this->segmentB.GetColor().GetRedComponent(), this->segmentB.GetColor().GetGreenComponent(), this->segmentB.GetColor().GetBlueComponent(), 1.0f));
		this->segmentC.SetColor(Color(this->segmentC.GetColor().GetRedComponent(), this->segmentC.GetColor().GetGreenComponent(), this->segmentC.GetColor().GetBlueComponent(), 1.0f));
		this->segmentD.SetColor(Color(this->segmentD.GetColor().GetRedComponent(), this->segmentD.GetColor().GetGreenComponent(), this->segmentD.GetColor().GetBlueComponent(), 1.0f));
		this->segmentE.SetColor(Color(this->segmentE.GetColor().GetRedComponent(), this->segmentE.GetColor().GetGreenComponent(), this->segmentE.GetColor().GetBlueComponent(), 0.1f));
		this->segmentF.SetColor(Color(this->segmentF.GetColor().GetRedComponent(), this->segmentF.GetColor().GetGreenComponent(), this->segmentF.GetColor().GetBlueComponent(), 0.1f));
		this->segmentG.SetColor(Color(this->segmentG.GetColor().GetRedComponent(), this->segmentG.GetColor().GetGreenComponent(), this->segmentG.GetColor().GetBlueComponent(), 1.0f));
		break;
	case '4':
		this->segmentA.SetColor(Color(this->segmentA.GetColor().GetRedComponent(), this->segmentA.GetColor().GetGreenComponent(), this->segmentA.GetColor().GetBlueComponent(), 0.1f));
		this->segmentB.SetColor(Color(this->segmentB.GetColor().GetRedComponent(), this->segmentB.GetColor().GetGreenComponent(), this->segmentB.GetColor().GetBlueComponent(), 1.0f));
		this->segmentC.SetColor(Color(this->segmentC.GetColor().GetRedComponent(), this->segmentC.GetColor().GetGreenComponent(), this->segmentC.GetColor().GetBlueComponent(), 1.0f));
		this->segmentD.SetColor(Color(this->segmentD.GetColor().GetRedComponent(), this->segmentD.GetColor().GetGreenComponent(), this->segmentD.GetColor().GetBlueComponent(), 0.1f));
		this->segmentE.SetColor(Color(this->segmentE.GetColor().GetRedComponent(), this->segmentE.GetColor().GetGreenComponent(), this->segmentE.GetColor().GetBlueComponent(), 0.1f));
		this->segmentF.SetColor(Color(this->segmentF.GetColor().GetRedComponent(), this->segmentF.GetColor().GetGreenComponent(), this->segmentF.GetColor().GetBlueComponent(), 1.0f));
		this->segmentG.SetColor(Color(this->segmentG.GetColor().GetRedComponent(), this->segmentG.GetColor().GetGreenComponent(), this->segmentG.GetColor().GetBlueComponent(), 1.0f));
		break;
	case '5':
		this->segmentA.SetColor(Color(this->segmentA.GetColor().GetRedComponent(), this->segmentA.GetColor().GetGreenComponent(), this->segmentA.GetColor().GetBlueComponent(), 1.0f));
		this->segmentB.SetColor(Color(this->segmentB.GetColor().GetRedComponent(), this->segmentB.GetColor().GetGreenComponent(), this->segmentB.GetColor().GetBlueComponent(), 0.1f));
		this->segmentC.SetColor(Color(this->segmentC.GetColor().GetRedComponent(), this->segmentC.GetColor().GetGreenComponent(), this->segmentC.GetColor().GetBlueComponent(), 1.0f));
		this->segmentD.SetColor(Color(this->segmentD.GetColor().GetRedComponent(), this->segmentD.GetColor().GetGreenComponent(), this->segmentD.GetColor().GetBlueComponent(), 1.0f));
		this->segmentE.SetColor(Color(this->segmentE.GetColor().GetRedComponent(), this->segmentE.GetColor().GetGreenComponent(), this->segmentE.GetColor().GetBlueComponent(), 0.1f));
		this->segmentF.SetColor(Color(this->segmentF.GetColor().GetRedComponent(), this->segmentF.GetColor().GetGreenComponent(), this->segmentF.GetColor().GetBlueComponent(), 1.0f));
		this->segmentG.SetColor(Color(this->segmentG.GetColor().GetRedComponent(), this->segmentG.GetColor().GetGreenComponent(), this->segmentG.GetColor().GetBlueComponent(), 1.0f));
		break;
		break;
	case '6':
		this->segmentA.SetColor(Color(this->segmentA.GetColor().GetRedComponent(), this->segmentA.GetColor().GetGreenComponent(), this->segmentA.GetColor().GetBlueComponent(), 1.0f));
		this->segmentB.SetColor(Color(this->segmentB.GetColor().GetRedComponent(), this->segmentB.GetColor().GetGreenComponent(), this->segmentB.GetColor().GetBlueComponent(), 0.1f));
		this->segmentC.SetColor(Color(this->segmentC.GetColor().GetRedComponent(), this->segmentC.GetColor().GetGreenComponent(), this->segmentC.GetColor().GetBlueComponent(), 1.0f));
		this->segmentD.SetColor(Color(this->segmentD.GetColor().GetRedComponent(), this->segmentD.GetColor().GetGreenComponent(), this->segmentD.GetColor().GetBlueComponent(), 1.0f));
		this->segmentE.SetColor(Color(this->segmentE.GetColor().GetRedComponent(), this->segmentE.GetColor().GetGreenComponent(), this->segmentE.GetColor().GetBlueComponent(), 1.0f));
		this->segmentF.SetColor(Color(this->segmentF.GetColor().GetRedComponent(), this->segmentF.GetColor().GetGreenComponent(), this->segmentF.GetColor().GetBlueComponent(), 1.0f));
		this->segmentG.SetColor(Color(this->segmentG.GetColor().GetRedComponent(), this->segmentG.GetColor().GetGreenComponent(), this->segmentG.GetColor().GetBlueComponent(), 1.0f));
		break;
	case '7':
		this->segmentA.SetColor(Color(this->segmentA.GetColor().GetRedComponent(), this->segmentA.GetColor().GetGreenComponent(), this->segmentA.GetColor().GetBlueComponent(), 1.0f));
		this->segmentB.SetColor(Color(this->segmentB.GetColor().GetRedComponent(), this->segmentB.GetColor().GetGreenComponent(), this->segmentB.GetColor().GetBlueComponent(), 1.0f));
		this->segmentC.SetColor(Color(this->segmentC.GetColor().GetRedComponent(), this->segmentC.GetColor().GetGreenComponent(), this->segmentC.GetColor().GetBlueComponent(), 1.0f));
		this->segmentD.SetColor(Color(this->segmentD.GetColor().GetRedComponent(), this->segmentD.GetColor().GetGreenComponent(), this->segmentD.GetColor().GetBlueComponent(), 0.1f));
		this->segmentE.SetColor(Color(this->segmentE.GetColor().GetRedComponent(), this->segmentE.GetColor().GetGreenComponent(), this->segmentE.GetColor().GetBlueComponent(), 0.1f));
		this->segmentF.SetColor(Color(this->segmentF.GetColor().GetRedComponent(), this->segmentF.GetColor().GetGreenComponent(), this->segmentF.GetColor().GetBlueComponent(), 0.1f));
		this->segmentG.SetColor(Color(this->segmentG.GetColor().GetRedComponent(), this->segmentG.GetColor().GetGreenComponent(), this->segmentG.GetColor().GetBlueComponent(), 0.1f));
		break;
	case '8':
		this->segmentA.SetColor(Color(this->segmentA.GetColor().GetRedComponent(), this->segmentA.GetColor().GetGreenComponent(), this->segmentA.GetColor().GetBlueComponent(), 1.0f));
		this->segmentB.SetColor(Color(this->segmentB.GetColor().GetRedComponent(), this->segmentB.GetColor().GetGreenComponent(), this->segmentB.GetColor().GetBlueComponent(), 1.0f));
		this->segmentC.SetColor(Color(this->segmentC.GetColor().GetRedComponent(), this->segmentC.GetColor().GetGreenComponent(), this->segmentC.GetColor().GetBlueComponent(), 1.0f));
		this->segmentD.SetColor(Color(this->segmentD.GetColor().GetRedComponent(), this->segmentD.GetColor().GetGreenComponent(), this->segmentD.GetColor().GetBlueComponent(), 1.0f));
		this->segmentE.SetColor(Color(this->segmentE.GetColor().GetRedComponent(), this->segmentE.GetColor().GetGreenComponent(), this->segmentE.GetColor().GetBlueComponent(), 1.0f));
		this->segmentF.SetColor(Color(this->segmentF.GetColor().GetRedComponent(), this->segmentF.GetColor().GetGreenComponent(), this->segmentF.GetColor().GetBlueComponent(), 1.0f));
		this->segmentG.SetColor(Color(this->segmentG.GetColor().GetRedComponent(), this->segmentG.GetColor().GetGreenComponent(), this->segmentG.GetColor().GetBlueComponent(), 1.0f));
		break;
	case '9':
		this->segmentA.SetColor(Color(this->segmentA.GetColor().GetRedComponent(), this->segmentA.GetColor().GetGreenComponent(), this->segmentA.GetColor().GetBlueComponent(), 1.0f));
		this->segmentB.SetColor(Color(this->segmentB.GetColor().GetRedComponent(), this->segmentB.GetColor().GetGreenComponent(), this->segmentB.GetColor().GetBlueComponent(), 1.0f));
		this->segmentC.SetColor(Color(this->segmentC.GetColor().GetRedComponent(), this->segmentC.GetColor().GetGreenComponent(), this->segmentC.GetColor().GetBlueComponent(), 1.0f));
		this->segmentD.SetColor(Color(this->segmentD.GetColor().GetRedComponent(), this->segmentD.GetColor().GetGreenComponent(), this->segmentD.GetColor().GetBlueComponent(), 0.1f));
		this->segmentE.SetColor(Color(this->segmentE.GetColor().GetRedComponent(), this->segmentE.GetColor().GetGreenComponent(), this->segmentE.GetColor().GetBlueComponent(), 0.1f));
		this->segmentF.SetColor(Color(this->segmentF.GetColor().GetRedComponent(), this->segmentF.GetColor().GetGreenComponent(), this->segmentF.GetColor().GetBlueComponent(), 1.0f));
		this->segmentG.SetColor(Color(this->segmentG.GetColor().GetRedComponent(), this->segmentG.GetColor().GetGreenComponent(), this->segmentG.GetColor().GetBlueComponent(), 1.0f));
		break;
	case '0':
		this->segmentA.SetColor(Color(this->segmentA.GetColor().GetRedComponent(), this->segmentA.GetColor().GetGreenComponent(), this->segmentA.GetColor().GetBlueComponent(), 1.0f));
		this->segmentB.SetColor(Color(this->segmentB.GetColor().GetRedComponent(), this->segmentB.GetColor().GetGreenComponent(), this->segmentB.GetColor().GetBlueComponent(), 1.0f));
		this->segmentC.SetColor(Color(this->segmentC.GetColor().GetRedComponent(), this->segmentC.GetColor().GetGreenComponent(), this->segmentC.GetColor().GetBlueComponent(), 1.0f));
		this->segmentD.SetColor(Color(this->segmentD.GetColor().GetRedComponent(), this->segmentD.GetColor().GetGreenComponent(), this->segmentD.GetColor().GetBlueComponent(), 1.0f));
		this->segmentE.SetColor(Color(this->segmentE.GetColor().GetRedComponent(), this->segmentE.GetColor().GetGreenComponent(), this->segmentE.GetColor().GetBlueComponent(), 1.0f));
		this->segmentF.SetColor(Color(this->segmentF.GetColor().GetRedComponent(), this->segmentF.GetColor().GetGreenComponent(), this->segmentF.GetColor().GetBlueComponent(), 1.0f));
		this->segmentG.SetColor(Color(this->segmentG.GetColor().GetRedComponent(), this->segmentG.GetColor().GetGreenComponent(), this->segmentG.GetColor().GetBlueComponent(), 0.1f));
		break;
	}
}

