
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

		if (device->GetDrawBoard()->IsKeyDown(VK_RIGHT))
		{
			device->EnableShadow(true);
		}

		if ( device->GetDrawBoard()->IsKeyDown(VK_LEFT))
		{
			device->EnableReflection(true);
		}

		device->ClearBuffer();
		device->DrawScene();
		device->GetDrawBoard()->Update();
	}

	device->Close();

	delete device;

	return 0;
}