#pragma once
#include<vector>
#include"DrawBoard.h"
#include "Vector.h"
#include "Color.h"
#include "Camera.h"
#include "Sphere.h"
#include "Light.h"

#define _GET_ALPHA( c ) ( ( (c) & 0xFF000000 ) >> 24 )

#define _GET_RED( c ) ( ( (c) & 0x00FF0000 ) >> 16 )

#define _GET_GREEN( c ) ( ( (c) & 0x0000FF00 ) >> 8 )

#define _GET_BLUE( c ) ( (c) & 0x000000FF )

#define _SET_ALPHA( c, a ) ( (c) = ( (c) & 0x00FFFFFF ) | (a) << 24 )

#define _SET_RED( c, r ) ( (c) = ( (c) & 0xFF00FFFF ) | (r) << 16 )

#define _SET_GREEN( c, g ) ( (c) = ( (c) & 0xFFFF00FF ) | (g) << 8 )

#define _SET_BLUE( c, b ) ( (c) = ( (c) & 0xFFFFFF00 ) | (b) )

#define _COMBINE_COLOR( a, r, g, b ) ( (a) << 24 | (r) << 16 | (g) << 8 | (b) )

#define Round(x) (int((x)+0.5f))
#define PI 3.1415926

class Device
{
public:
	enum mode
	{
		_Lighting_Diffuse	= 0x00000001,
		_Lighting_Specular	= 0x00000002,
	};

private:
	int mWidth;
	int mHeight;

	Camera camera;
	DrawBoard* mDrawBoard;
	int** mFrameBuffer;

	float vieww;
	float viewh;

	int mDrawMode;

	std::vector<Light> lights;
	std::vector<Sphere> spheres;

public:
	Device() : mWidth(800), mHeight(600), mDrawBoard(NULL), mFrameBuffer(NULL) { }
	Device(int width, int height) :mWidth(width), mHeight(height), mDrawBoard(NULL), mFrameBuffer(NULL) { }
	~Device() { }
	inline DrawBoard* GetDrawBoard() { return mDrawBoard; }

	inline bool IsDiffuseEnabled() const
		{ return (mDrawMode & _Lighting_Diffuse) != 0; }
	inline void EnableDiffuse(bool enable)
		{ mDrawMode = enable ? (mDrawMode | _Lighting_Diffuse) : (mDrawMode & ~_Lighting_Diffuse); }

	inline bool IsSpecularEnabled() const
		{ return (mDrawMode & _Lighting_Specular) != 0; }
	inline void EnableSpecular(bool enable)
		{ mDrawMode = enable ? (mDrawMode | _Lighting_Specular) : (mDrawMode & ~_Lighting_Specular); }

	void Init(int w, int h);
	void ClearBuffer();
	void Close();

	void DrawPoint(const Vector2& point, const Color& color) const;
	void DrawScene() const;
	Vector3 CanvasToViewPort(float x, float y) const;
	Color TracRay( Vector3 v ) const;
	Vector2 Intersect(Vector3 dir, Sphere sphere) const;

	float ComputeLight(Vector3 point, Vector3 normal, Vector3 view, float s) const;
};