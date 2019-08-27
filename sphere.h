#pragma once
#include "Vector.h"
#include "Color.h"

class Sphere
{
public:
	Vector3 center;
	float	radius;
	Color	color;

public:
	Sphere() :center(Vector3(0.0f, 0.0f, 0.0f)), radius(0.0f), color(Color(255.0f, 255.0f, 255.0f)) { }
	Sphere(Vector3 center, float r, Color color) :center(center), radius(r), color(color){ }
};
