#pragma once
//Ϊ���������ɫ�������������ξ�������ɫ��Ϣ�������ж��������ɫ��Ϣ

#include <string>
#include <iostream>
using namespace std;

#include <GL/glew.h>

class Shader
{
public:
	Shader(const string& fileName);//��ɫ���ı�·��

	void Bind();	//����ɫ��
	~Shader();

private:
	static const unsigned int NUM_SHADERS = 2;		//����
	GLuint m_pragmram;		//������ɫ��
	GLuint m_shader[NUM_SHADERS];		//����������ɫ����������ɫ����ƬԴ��ɫ��
};