#include"Display.h"
#include"GL\glew.h"		//openGL API
Display::Display(int width, int height, const string& title)
{
	//���SDL2
	SDL_Init(SDL_INIT_EVERYTHING);		//��ʼ��SDL2����Ҫ�����ж���


	//���ô�������
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);		
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);		//����λ��
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);		//����������,��ʾһ��˫�ػ�����
	
	m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);		//SDL2��һ��C�⣬����SDL_Window�����ڱ�־����Ϊopengl����
	m_glContext = SDL_GL_CreateContext(m_window);		//ͨ�����ڷ���context���󣬴��������Ĵ���

	GLenum status = glewInit();		//glew��ʼ��
	if (status != GLEW_OK)		//�����ʼ��ʧ��
	{
		cerr << "Glew Init failure" << endl;		//cerr��iostream����
	}

	m_isClosed = false;		//��ʼ��ʱ���˳��߼�Ϊfalse
}
Display::~Display()
{
	//������ͷ�
	SDL_GL_DeleteContext(m_glContext);		//�ͷ�context
	SDL_DestroyWindow(m_window);		//�ͷŴ���
	SDL_Quit();		//sdl�˳�
}

void Display::Update()
{
	SDL_GL_SwapWindow(m_window);		//����������

	//����¼�����
	SDL_Event e;
	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_QUIT)
		{
			m_isClosed = true;		//�˳�����m_isClosed���Ƴ����˳��߼�
		}
	}
}

bool Display::IsClosed()
{
	return m_isClosed;		//���س����˳��߼���־
}

void Display::Clear(float r, float g, float b, float a)
{
	glClearColor(r, g, b, a);//�ѱ���ɫ���Ϊ��ɫ
	glClear(GL_COLOR_BUFFER_BIT);//��λ���
}