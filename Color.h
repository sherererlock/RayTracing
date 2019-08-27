#pragma once
#include"Vector.h"

class Color
{
public:
	float r, g, b;

	Color( ) { }
	Color(float r, float g, float b) : r(r), g(g), b(b) { }

	Color operator* (const Color& color) const
	{
		return Color(r * color.r, g * color.g, b * color.b);
	}

	Color operator* (float factor) const
	{
		return Color(r * factor, g * factor, b * factor);
	}

	Color operator+ (const Color& color) const
	{
		return Color(r + color.r, g + color.g, b + color.b);
	}

	Color operator* (const Vector3& intesity) const
	{
		return Color(r * intesity.x, g * intesity.y, b * intesity.z);
	}
};
