#pragma once
//���䶥�㻺�����,����һ����ɫ������

#include<glm\glm.hpp>
#include<GL\glew.h>

class Vertex		//���嶥���������ͣ�������
{
public:
	Vertex(const glm::vec3& pos)		//��ά����
	{
		this->pos = pos;
	}

private:
	glm::vec3 pos;		//�����λ����Ϣ
};

class Mesh		//������
{
public:
	Mesh(Vertex* vertices,unsigned int numVertices);
	void Draw();//��mesh���Ƴ�����ִ����������Ⱦ����
	~Mesh();

private:
	//ö��
	enum
	{
		POSITION_VB,
		NUM_BUFFERS
	};
	GLuint m_vertexArrayObject;		//�������������
	GLuint m_vertexArrayBuffers[NUM_BUFFERS];		//����������ƣ�NUM_BUFFERS�������
	unsigned int m_drawCount;		//���ƶ���ĸ���
};
