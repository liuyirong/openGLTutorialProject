#include"Mesh.h"

Mesh::Mesh(Vertex* vertices, unsigned int numVertices)
{
	m_drawCount = numVertices;		//传递顶点个数

	//调用OPENGL函数
	glGenVertexArrays(1, &m_vertexArrayObject);//分配顶点数组对象，保存一系列的顶点数据
	glBindVertexArray(m_vertexArrayObject);//创建并绑定一个顶点数据对象

	//分配顶点缓存对象，上两个函数创建的数据将保存在顶点缓存中，顶点缓存对象的初始化过程和顶点数组对象的创建过程类似
	glGenBuffers(NUM_BUFFERS, m_vertexArrayBuffers);//创建顶点缓存对象的名称
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[POSITION_VB]);//OPENGL有很多种类的缓存对象，绑定一个缓存时需要制定所定义的类型,顶点属性数据，m_vertexArrayBuffers[POSITION_VB]顶点缓存对象名称

	//要把顶点数据传输到缓存对象中
	glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(vertices[0]), vertices, GL_STATIC_DRAW);//作用：1）分配顶点数据所需的存储空间。2）将数据从应用程序的数组拷贝到OpenGL服务端的内存中


	//启用与着色器相关的属性，位置，索引相关的顶点数组
	glEnableVertexAttribArray(0);//0表示着色器中属性位置索引
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);//将顶点数据输入到顶点着色器，需要在着色器中声明一个ying变量，关联顶点属性数组

	glBindVertexArray(0);//0表示程序不再使用程序分配的任何顶点对象和m_vertexArrayObject相对应
}

void Mesh::Draw()
{
	glBindVertexArray(m_vertexArrayObject);//创建并绑定一个顶点数据对象
	glDrawArrays(GL_TRIANGLES, 0, m_drawCount);//opengl下顶点数据管道的传输,使用当前绑定的几何数组来创建一系列的几何图元

	glBindVertexArray(0); //对绑定释放
}

Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &m_vertexArrayObject);//释放顶点数组对象
}