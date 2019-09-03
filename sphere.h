#pragma once
#include "Vector.h"
#include "Color.h"

class Sphere
{
public:
	Vector3 center;
	float	radius;
	float	squareofradius;
	Color	color;
	float	specular;
	float	reflection;
	float	optimizenumber;

public:
	Sphere() :center(Vector3(0.0f, 0.0f, 0.0f)), radius(0.0f), color(Color(255.0f, 255.0f, 255.0f)), specular(-1), reflection(0.0f), squareofradius(0.0f){ }
	Sphere(Vector3 center, float r, Color color, float s, float reflect) :center(center), radius(r), color(color), specular(s),reflection(reflect)
	{
		squareofradius = radius * radius;
	}
};
