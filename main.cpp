#include<iostream>
using namespace std;

#include"GL\glew.h"
#include"Display.h"
#include "Mesh.h"

int main(int argc, char** argv)		//SDL2对main函数有特殊要求
{
	Display display(800, 600, "OpenGL study");		//窗口显示display对象

	Vertex vertices[] = { Vertex(glm::vec3(-0.5,-0.5,0)),
		Vertex(glm::vec3(0,0.5,0)),
		Vertex(glm::vec3(0.5,-0.5,0)) };		//顶点数组对象
	Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));	//mesh对象，参数为顶点对象和顶点对象个数

	while (!display.IsClosed())		//如果程序没有退出,while大循环
	{
		display.Clear(0.0f, 0.15f, 0.3f, 1.0f);

		mesh.Draw();

		display.Update();		//更新
	}
	return 0;
}