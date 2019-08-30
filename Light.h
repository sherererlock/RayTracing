#pragma once
#include "Color.h"
#include "Vector.h"

class Light
{
public:
	enum
	{
		_Light_Point,
		_Light_Directional,
		_Light_Ambient
	};

	Vector3		mVector;
	float		mIntensity;
	int			mType;

	Light(Vector3 vec, float i, int type) :mVector(vec), mIntensity(i), mType(type) {}
};