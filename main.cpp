#include<iostream>
using namespace std;

#include"GL\glew.h"
#include"Display.h"
int main(int argc, char** argv)		//SDL2��main����������Ҫ��
{
	Display display(800, 600, "OpenGL study");		//������ʾdisplay����

	while (!display.IsClosed())		//�������û���˳�,while��ѭ��
	{
		display.Clear(0.0f, 0.15f, 0.3f, 1.0f);

		display.Update();		//����
	}
	return 0;
}