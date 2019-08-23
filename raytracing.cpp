
#include<iostream>
#include"Device.h"

Device* device = NULL;

void DrawLine(int y)
{
	for (int x = 0; x < 600; x++)
		device->DrawPoint(Vector3(x, y, 0.0f), Color(255.0f, 0.0f, 0.0f, 1.0f));
}

int main()
{
	device = new Device();
	device->Init(800, 600);
	int y = 0;
	while (true)
	{
		if (device->GetDrawBoard( )->IsKeyDown(VK_ESCAPE))
			break;

		if ( device->GetDrawBoard()->IsKeyDown(87))
		{

		}
		else if (device->GetDrawBoard()->IsKeyDown(83))
		{

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

		if (y > 600)
			y = 0;

		device->ClearBuffer();

		DrawLine( y );

		y++;
		device->GetDrawBoard()->Update();
	}

	device->Close();

	delete device;

	return 0;
}