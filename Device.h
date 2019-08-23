#pragma once
#include<vector>
#include"DrawBoard.h"
#include "Vector.h"
#include "Color.h"

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
private:
	int mWidth;
	int mHeight;

	DrawBoard* mDrawBoard;
	int** mFrameBuffer;

public:
	Device() : mWidth(800), mHeight(600), mDrawBoard(NULL), mFrameBuffer(NULL) { }
	Device(int width, int height) :mWidth(width), mHeight(height), mDrawBoard(NULL), mFrameBuffer(NULL) { }
	~Device() { }
	inline DrawBoard* GetDrawBoard() { return mDrawBoard; }

	void Init(int w, int h);
	void ClearBuffer();
	void Close();

	void DrawPoint(const Vector3& point, const Color& color) const;
};