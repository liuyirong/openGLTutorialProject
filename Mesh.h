#pragma once
//分配顶点缓存对象,绘制一个白色三角形

#include<glm\glm.hpp>
#include<GL\glew.h>

class Vertex		//定义顶点数据类型，顶点类
{
public:
	Vertex(const glm::vec3& pos)		//三维向量
	{
		this->pos = pos;
	}

private:
	glm::vec3 pos;		//顶点的位置信息
};

class Mesh		//网格类
{
public:
	Mesh(Vertex* vertices,unsigned int numVertices);
	void Draw();//把mesh绘制出来，执行真正的渲染操作
	~Mesh();

private:
	//枚举
	enum
	{
		POSITION_VB,
		NUM_BUFFERS
	};
	GLuint m_vertexArrayObject;		//顶点数组对象名
	GLuint m_vertexArrayBuffers[NUM_BUFFERS];		//缓存对象名称，NUM_BUFFERS缓存个数
	unsigned int m_drawCount;		//绘制顶点的个数
};
