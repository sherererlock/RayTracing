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
	camera.fov = 0.5f * PI;
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

void Device::DrawPoint(const Vector3& point, const Color& color) const
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
	for (int cy = -mHeight/2; cy < mHeight / 2; cy++)
	{
		for (int cx = -mWidth / 2; cx < mWidth / 2; cx++)
		{
			Vector3 v = CanvasToViewPort(cx, cy);

		}
	}
}

Vector3 Device::CanvasToViewPort(float x, float y) const
{
	float vw = 1;
	float vh = 1;
	return Vector3(x * vw / mWidth, y * vh / mHeight, camera.distance);
}

Color Device::TracRay(Vector3 v) const
{
	Vector3 raydir = ( v - camera.eye ).Normalize( );

}