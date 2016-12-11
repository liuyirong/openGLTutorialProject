#include"Display.h"
#include"GL\glew.h"		//openGL API
Display::Display(int width, int height, const string& title)
{
	//添加SDL2
	SDL_Init(SDL_INIT_EVERYTHING);		//初始化SDL2所需要的所有东西


	//设置窗口属性
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);		
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);		//缓冲位数
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);		//交换缓冲区,表示一个双重缓冲区
	
	m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);		//SDL2是一个C库，创建SDL_Window，窗口标志设置为opengl窗口
	m_glContext = SDL_GL_CreateContext(m_window);		//通过窗口返回context对象，窗口上下文创建

	GLenum status = glewInit();		//glew初始化
	if (status != GLEW_OK)		//如果初始化失败
	{
		cerr << "Glew Init failure" << endl;		//cerr在iostream库中
	}

	m_isClosed = false;		//初始化时，退出逻辑为false
}
Display::~Display()
{
	//对象的释放
	SDL_GL_DeleteContext(m_glContext);		//释放context
	SDL_DestroyWindow(m_window);		//释放窗口
	SDL_Quit();		//sdl退出
}

void Display::Update()
{
	SDL_GL_SwapWindow(m_window);		//交换缓冲区

	//添加事件处理
	SDL_Event e;
	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_QUIT)
		{
			m_isClosed = true;		//退出程序，m_isClosed控制程序退出逻辑
		}
	}
}

bool Display::IsClosed()
{
	return m_isClosed;		//返回程序退出逻辑标志
}

void Display::Clear(float r, float g, float b, float a)
{
	glClearColor(r, g, b, a);//把背景色清空为蓝色
	glClear(GL_COLOR_BUFFER_BIT);//按位清空
}