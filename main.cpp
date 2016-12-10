#include<iostream>
using namespace std;

#include"GL\glew.h"
#include"Display.h"
int main(int argc, char** argv)
{
	Display display(800, 600, "OpenGL study");

	while (!display.IsClosed())
	{
		display.Clear(0.0f, 0.15f, 0.3f, 1.0f);

		display.Update();
	}
	return 0;
}