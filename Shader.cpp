#include "Shader.h"
#include <fstream>

//检测着色器或者管理着色器是否存在错误
static void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const string& errorMessage)
{
	GLint success = 0;
	GLchar error[1024] = { 0 };
	if (isProgram)//着色器或者管理着色器
	{
		glGetProgramiv(shader, flag, &success);
	}
	else
	{
		glGetShaderiv(shader, flag, &success);
	}

	if (success == GL_FALSE)	//如果失败
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

//加载着色器文件，并返回着色器的所有内容
static string LoadShader(const string& fileName)//着色器路径
{
	ifstream file;
	file.open(fileName.c_str());//打开着色器文件

	string output;
	string line;

	if (file.is_open())
	{
		while (file.good())
		{
			getline(file, line); //不停获取每一行
			output.append(line + "\n");
		}
	}
	else
	{
		cerr << "Unable to load shader:" << fileName << endl;
	}
	return output;	//返回着色器所有内容
}

//创建着色器
static GLuint CreateShader(const string& text, GLenum shaderType)
{
	GLuint shader = glCreateShader(shaderType);		//根据类型创建着色器
	if (shader == 0)	//创建失败
	{
		cerr << "Error: shader creation failure" << endl;
	}

	//获得着色器字符串
	const GLchar* shaderSourceString[1];	//GLchar openGL自定义类型，方便跨平台
	//获得着色器字符串的长度
	GLint shaderSourceStringLength[1];

	//传值
	shaderSourceString[0] = text.c_str();
	shaderSourceStringLength[0] = text.length();

	//向shader中导入写好的着色器
	glShaderSource(shader, 1, shaderSourceString, shaderSourceStringLength);

	//编译shader
	glCompileShader(shader);
	//检查编译状态
	CheckShaderError(shader, GL_COMPILE_STATUS, false, "error: shader compilation failed");

	return shader;  //返回创建成功的shader
}

Shader::Shader(const string & fileName)
{
	m_pragmram = glCreateProgram();		//创建program

	//读取着色器文件，并且返回创建后的着色器（着色器文本./res中）
	m_shader[0] = CreateShader(LoadShader(fileName + ".vs"),GL_VERTEX_SHADER);	//顶点着色器
	m_shader[1] = CreateShader(LoadShader(fileName + ".fs"),GL_FRAGMENT_SHADER);	//片源着色器

	//将shader导入program中
	for (unsigned int i=0;i<NUM_SHADERS;i++) 
	{
		glAttachShader(m_pragmram, m_shader[i]);//将着色器加载到program中
	}

	//链接program
	glLinkProgram(m_pragmram);
	//检查program是否调用正确
	CheckShaderError(m_pragmram, GL_LINK_STATUS, true, "error: progrma linking invalid");
	
	//验证program
	glValidateProgram(m_pragmram);
	CheckShaderError(m_pragmram, GL_VALIDATE_STATUS, true, "error: progrma validate invalid");
}

void Shader::Bind()
{
	glUseProgram(m_pragmram);  //使用加载好的program绑定着色器，使用program
}

Shader::~Shader()
{
	//着色器使用完了的卸载
	for (unsigned int i = 0; i < NUM_SHADERS; i++)
	{
		glDetachShader(m_pragmram, m_shader[i]);//将shader从program中卸载
		glDeleteShader(m_shader[i]);	//删除掉shader
	}
	glDeleteProgram(m_pragmram);	//删除program
}
