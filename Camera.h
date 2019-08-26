#pragma once

#include "Vector.h"

class Camera
{
public:
	Vector3		up;
	Vector3		look;
	Vector3		eye;
	float		distance;
	float		fov;
};