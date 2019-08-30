
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
	device->Init(800, 800);
	while (true)
	{
		if (device->GetDrawBoard( )->IsKeyDown(VK_ESCAPE))
			break;

		if ( device->GetDrawBoard()->IsKeyDown(VK_UP))
		{
			device->EnableDiffuse(true);
		}
		else if (device->GetDrawBoard()->IsKeyDown(VK_DOWN))
		{
			device->EnableDiffuse(false);
		}
		else if (device->GetDrawBoard()->IsKeyDown(65))
		{
		}
		else if ( device->GetDrawBoard()->IsKeyDown(68))
		{
		}
		else if (device->GetDrawBoard()->IsKeyDown(VK_RIGHT))
		{
		}
		else if (device->GetDrawBoard()->IsKeyDown(VK_LEFT))
		{

		}
		else if (device->GetDrawBoard()->IsKeyDown(VK_UP))
		{

		}
		else if (device->GetDrawBoard()->IsKeyDown(VK_DOWN))
		{
	
		}

		device->ClearBuffer();
		device->DrawScene();
		device->GetDrawBoard()->Update();
	}

	device->Close();

	delete device;

	return 0;
}