#include<iostream>
using namespace std;

#include"GL\glew.h"
#include"Display.h"
#include "Mesh.h"

int main(int argc, char** argv)		//SDL2��main����������Ҫ��
{
	Display display(800, 600, "OpenGL study");		//������ʾdisplay����

	Vertex vertices[] = { Vertex(glm::vec3(-0.5,-0.5,0)),
		Vertex(glm::vec3(0,0.5,0)),
		Vertex(glm::vec3(0.5,-0.5,0)) };		//�����������
	Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));	//mesh���󣬲���Ϊ�������Ͷ���������

	while (!display.IsClosed())		//�������û���˳�,while��ѭ��
	{
		display.Clear(0.0f, 0.15f, 0.3f, 1.0f);

		mesh.Draw();

		display.Update();		//����
	}
	return 0;
}