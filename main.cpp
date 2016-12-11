#include<iostream>
using namespace std;

#include"GL\glew.h"
#include"Display.h"
int main(int argc, char** argv)		//SDL2对main函数有特殊要求
{
	Display display(800, 600, "OpenGL study");		//窗口显示display对象

	while (!display.IsClosed())		//如果程序没有退出,while大循环
	{
		display.Clear(0.0f, 0.15f, 0.3f, 1.0f);

		display.Update();		//更新
	}
	return 0;
}