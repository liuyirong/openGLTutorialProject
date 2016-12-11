#include"Mesh.h"

Mesh::Mesh(Vertex* vertices, unsigned int numVertices)
{
	m_drawCount = numVertices;		//���ݶ������

	//����OPENGL����
	glGenVertexArrays(1, &m_vertexArrayObject);//���䶥��������󣬱���һϵ�еĶ�������
	glBindVertexArray(m_vertexArrayObject);//��������һ���������ݶ���

	//���䶥�㻺������������������������ݽ������ڶ��㻺���У����㻺�����ĳ�ʼ�����̺Ͷ����������Ĵ�����������
	glGenBuffers(NUM_BUFFERS, m_vertexArrayBuffers);//�������㻺����������
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[POSITION_VB]);//OPENGL�кܶ�����Ļ�����󣬰�һ������ʱ��Ҫ�ƶ������������,�����������ݣ�m_vertexArrayBuffers[POSITION_VB]���㻺���������

	//Ҫ�Ѷ������ݴ��䵽���������
	glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(vertices[0]), vertices, GL_STATIC_DRAW);//���ã�1�����䶥����������Ĵ洢�ռ䡣2�������ݴ�Ӧ�ó�������鿽����OpenGL����˵��ڴ���


	//��������ɫ����ص����ԣ�λ�ã�������صĶ�������
	glEnableVertexAttribArray(0);//0��ʾ��ɫ��������λ������
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);//�������������뵽������ɫ������Ҫ����ɫ��������һ��ying����������������������

	glBindVertexArray(0);//0��ʾ������ʹ�ó��������κζ�������m_vertexArrayObject���Ӧ
}

void Mesh::Draw()
{
	glBindVertexArray(m_vertexArrayObject);//��������һ���������ݶ���
	glDrawArrays(GL_TRIANGLES, 0, m_drawCount);//opengl�¶������ݹܵ��Ĵ���,ʹ�õ�ǰ�󶨵ļ�������������һϵ�еļ���ͼԪ

	glBindVertexArray(0); //�԰��ͷ�
}

Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &m_vertexArrayObject);//�ͷŶ����������
}