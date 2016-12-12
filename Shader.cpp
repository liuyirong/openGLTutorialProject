#include "Shader.h"
#include <fstream>

//�����ɫ�����߹�����ɫ���Ƿ���ڴ���
static void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const string& errorMessage)
{
	GLint success = 0;
	GLchar error[1024] = { 0 };
	if (isProgram)//��ɫ�����߹�����ɫ��
	{
		glGetProgramiv(shader, flag, &success);
	}
	else
	{
		glGetShaderiv(shader, flag, &success);
	}

	if (success == GL_FALSE)	//���ʧ��
	{
		if (isProgram)
		{
			glGetProgramInfoLog(shader, sizeof(error), NULL, error);
		}
		else
		{
			glGetShaderInfoLog(shader, sizeof(error), NULL, error);
		}
		cerr << errorMessage << ":'" << error << "'" << endl;
	}
}

//������ɫ���ļ�����������ɫ������������
static string LoadShader(const string& fileName)//��ɫ��·��
{
	ifstream file;
	file.open(fileName.c_str());//����ɫ���ļ�

	string output;
	string line;

	if (file.is_open())
	{
		while (file.good())
		{
			getline(file, line); //��ͣ��ȡÿһ��
			output.append(line + "\n");
		}
	}
	else
	{
		cerr << "Unable to load shader:" << fileName << endl;
	}
	return output;	//������ɫ����������
}

//������ɫ��
static GLuint CreateShader(const string& text, GLenum shaderType)
{
	GLuint shader = glCreateShader(shaderType);		//�������ʹ�����ɫ��
	if (shader == 0)	//����ʧ��
	{
		cerr << "Error: shader creation failure" << endl;
	}

	//�����ɫ���ַ���
	const GLchar* shaderSourceString[1];	//GLchar openGL�Զ������ͣ������ƽ̨
	//�����ɫ���ַ����ĳ���
	GLint shaderSourceStringLength[1];

	//��ֵ
	shaderSourceString[0] = text.c_str();
	shaderSourceStringLength[0] = text.length();

	//��shader�е���д�õ���ɫ��
	glShaderSource(shader, 1, shaderSourceString, shaderSourceStringLength);

	//����shader
	glCompileShader(shader);
	//������״̬
	CheckShaderError(shader, GL_COMPILE_STATUS, false, "error: shader compilation failed");

	return shader;  //���ش����ɹ���shader
}

Shader::Shader(const string & fileName)
{
	m_pragmram = glCreateProgram();		//����program

	//��ȡ��ɫ���ļ������ҷ��ش��������ɫ������ɫ���ı�./res�У�
	m_shader[0] = CreateShader(LoadShader(fileName + ".vs"),GL_VERTEX_SHADER);	//������ɫ��
	m_shader[1] = CreateShader(LoadShader(fileName + ".fs"),GL_FRAGMENT_SHADER);	//ƬԴ��ɫ��

	//��shader����program��
	for (unsigned int i=0;i<NUM_SHADERS;i++) 
	{
		glAttachShader(m_pragmram, m_shader[i]);//����ɫ�����ص�program��
	}

	//����program
	glLinkProgram(m_pragmram);
	//���program�Ƿ������ȷ
	CheckShaderError(m_pragmram, GL_LINK_STATUS, true, "error: progrma linking invalid");
	
	//��֤program
	glValidateProgram(m_pragmram);
	CheckShaderError(m_pragmram, GL_VALIDATE_STATUS, true, "error: progrma validate invalid");
}

void Shader::Bind()
{
	glUseProgram(m_pragmram);  //ʹ�ü��غõ�program����ɫ����ʹ��program
}

Shader::~Shader()
{
	//��ɫ��ʹ�����˵�ж��
	for (unsigned int i = 0; i < NUM_SHADERS; i++)
	{
		glDetachShader(m_pragmram, m_shader[i]);//��shader��program��ж��
		glDeleteShader(m_shader[i]);	//ɾ����shader
	}
	glDeleteProgram(m_pragmram);	//ɾ��program
}
