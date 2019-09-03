
#include<iostream>
#include"Device.h"

Device* device = NULL;

void DrawLine(int y)
{
	for (int x = 0; x < 600; x++)
		device->DrawPoint(Vector2(x, y), Color(255.0f, 0.0f, 0.0f));
}

int main()
{
	device = new Device();
	device->Init(400, 400);

	//device->EnableDiffuse(true);
	//device->EnableSpecular(true);
	//device->EnableShadow(true);
	//device->EnableReflection(true);

	SYSTEMTIME sys;
	float timeold, timenew;
	GetLocalTime(&sys);
	timeold = sys.wSecond * 1000 + sys.wMilliseconds;
	while (true)
	{
		if (device->GetDrawBoard( )->IsKeyDown(VK_ESCAPE))
			break;

		if ( device->GetDrawBoard()->IsKeyDown(VK_UP))
		{
			device->EnableDiffuse(true);
		}

		if (device->GetDrawBoard()->IsKeyDown(VK_DOWN))
		{
			device->EnableSpecular(true);
		}

		if (device->GetDrawBoard()->IsKeyDown(VK_LEFT))
		{
			device->EnableShadow(true);
		}

		if ( device->GetDrawBoard()->IsKeyDown(VK_RIGHT))
		{
			device->EnableReflection(true);
		}

		device->ClearBuffer();
		device->DrawScene();
		GetLocalTime(&sys);
		timenew = sys.wSecond * 1000 + sys.wMilliseconds;
		std::cout << timenew - timeold << std::endl;
		device->GetDrawBoard()->Update();
		timeold = timenew;
		Sleep(1);
	}

	device->Close();

	delete device;

	return 0;
}