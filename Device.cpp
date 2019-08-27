#include<math.h>
#include"Device.h"
#include"DrawBoard.h"

void Device::Init(int w, int h)
{
	mWidth = w;
	mHeight = h;
	mDrawBoard = new DrawBoard();
	mDrawBoard->Init(w, h);
	int* fb = (int*)mDrawBoard->GetFramebuffer();
	mFrameBuffer = (int**)malloc(h * sizeof(int*));

	for (int i = 0; i < h; i++)
		mFrameBuffer[i] = fb + i * w;

	camera.eye = Vector3(0.0f, 0.0f, 0.0f);
	camera.look = Vector3(0.0f, 0.0f, 1.0f);
	camera.up = Vector3(0.0f, 1.0f, 0.0f);
	camera.distance = 1.0f;
	camera.fov = 53 / 180 * PI;
	vieww = 1.0f / mWidth;
	viewh = 1.0f / mHeight;

	spheres.push_back(Sphere(Vector3(0.0f, -1.0f, 3.0f), 1.0f, Color(255.0f, 0.0f, 0.0f)));
	spheres.push_back(Sphere(Vector3(2.0f, 0.0f, 4.0f), 1.0f, Color(0.0f, 0.0f, 255.0f)));
	spheres.push_back(Sphere(Vector3(-2.0f, 0.0f, 4.0f), 1.0f, Color(0.0f, 255.0f, 0.0f)));
}

void Device::ClearBuffer()
{
	for (int y = 0; y < mHeight; y++)
	{
		for (int x = 0; x < mWidth; x++)
			mFrameBuffer[y][x] = 0;
	}
}

void Device::Close()
{
	if (mFrameBuffer != NULL)
	{
		free(mFrameBuffer);
		mFrameBuffer = NULL;
	}

	if (mDrawBoard != NULL)
		mDrawBoard->Close();

	delete mDrawBoard;
}

void Device::DrawPoint(const Vector2& point, const Color& color) const
{
	int x = Round(point.x);
	int y = Round(point.y);
	int r = Round(color.r);
	int g = Round(color.g);
	int b = Round(color.b);
	if (x >= mWidth || x < 0 || y < 0 || y >= mHeight)
		return;

	mFrameBuffer[y][x] = r << 16 | g << 8 | b;
}

void Device::DrawScene() const
{
	int hw = mWidth / 2;
	int hh = mHeight / 2;
	for (int cy = -hh; cy < hh; cy++)
	{
		for (int cx = -hw; cx < hw; cx++)
		{
			Vector3 v = CanvasToViewPort(cx, cy);
			Color color = TracRay(v);
			DrawPoint(Vector2(cx + hw, cy + hh), color);
		}
	}
}

Vector3 Device::CanvasToViewPort(float x, float y) const
{
	return Vector3(x * vieww, y * viewh, camera.distance);
}

Color Device::TracRay(Vector3 v) const
{
	Vector3 raydir = v - camera.eye;
	Sphere sphere;
	float closestt = INFINITE;
	for (int i = 0; i < spheres.size(); i++)
	{
		Vector2 t = Intersect(v, spheres.at(i));
		if (t.x > 1.0f && t.x < closestt)
		{
			sphere = spheres.at(i);
			closestt = t.x;
		}

		if (t.y > 1.0f && t.y < closestt)
		{
			sphere = spheres.at(i);
			closestt = t.y;
		}
	}

	return sphere.color;
}

Vector2 Device::Intersect(Vector3 dir, Sphere sphere) const
{
	Vector3 oc = camera.eye - sphere.center;

	float k1 = Vector3::Dot(dir, dir);
	float k2 = 2 * Vector3::Dot(oc, dir);
	float k3 = Vector3::Dot(oc, oc) - sphere.radius * sphere.radius;

	float D = k2 * k2 - 4 * k1* k3;
	if (D < 0)
		return Vector2(INFINITE, INFINITE);

	Vector2 s(0.0f, 0.0f);
	s.x = (-k2 + ::sqrt(D)) / (2 * k1);
	s.y = (-k2 - ::sqrt(D)) / (2 * k1);

	return s;
}