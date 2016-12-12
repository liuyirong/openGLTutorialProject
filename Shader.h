#pragma once
//为程序添加着色器，这样三角形就有了颜色信息，给所有顶点添加颜色信息

#include <string>
#include <iostream>
using namespace std;

#include <GL/glew.h>

class Shader
{
public:
	Shader(const string& fileName);//着色器文本路径

	void Bind();	//绑定着色器
	~Shader();

private:
	static const unsigned int NUM_SHADERS = 2;		//常数
	GLuint m_pragmram;		//管理着色器
	GLuint m_shader[NUM_SHADERS];		//定义两个着色器，顶点着色器和片源着色器
};