#pragma once
class Color
{
private:
	float redComponent;
	float greenComponent;
	float blueComponent;
	float alphaComponent;

public:
	Color() : redComponent(0.2f), greenComponent(0.6f), blueComponent(0.3f),
		alphaComponent(0.6f)
	{}

	Color(float redArgument, float greenArgument, float blueArgument, float alphaArgument)
	{
		this->redComponent = redArgument;
		this->greenComponent = greenArgument;
		this->blueComponent = blueArgument;
		this->alphaComponent = alphaArgument;
	}

	inline float GetRedComponent() const { return this->redComponent; }
	inline float GetGreenComponent() const { return this->greenComponent; }
	inline float GetBlueComponent() const { return this->blueComponent; }
	inline float GetAlphaComponent() const { return this->alphaComponent; }

	inline void SetRedComponent(float redToSet)
	{
		// Solo asigna redComponent si redToSet está en el rango [0.0, 1.0]
		this->redComponent = (redToSet >= 0.0 && redToSet <= 1.0) ? redToSet : this->redComponent;
	}


	inline void SetGreenComponent(float greenToSet)
	{
		if (greenToSet >= 0.0 && greenToSet <= 1.0)
		{
			this->greenComponent = greenToSet;
		}
	}

	inline void SetBlueComponent(float blueToSet)
	{
		if (blueToSet >= 0.0 && blueToSet <= 1.0)
		{
			this->blueComponent = blueToSet;
		}
	}

	inline void SetAlphaComponent(float alphaToSet)
	{
		if (alphaToSet >= 0.0 && alphaToSet <= 1.0)
		{
			this->alphaComponent = alphaToSet;
		}
	}


};

