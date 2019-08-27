#pragma once
#include "Vector.h"
#include "Color.h"

class Sphere
{
public:
	Vector3 origin;
	float	radius;
	Color	color;

public:
	Sphere() :origin(Vector3(0.0f, 0.0f, 0.0f)), radius(0.0f), color(Color(255.0f, 255.0f, 255.0f, 1.0f))
	{}
};
