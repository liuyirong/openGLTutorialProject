#pragma once		//ͷ�ļ�ֻ����һ��
//����SDL2��ʾ���ڵ���

#include <iostream>
using namespace std; 

#include"SDL2\SDL.h"

class Display
{
public:
	Display(int width, int height, const string& title);		//���ڿ���Լ�����
	~Display();

	void Update();//˫�ػ������-->�¼�����
	bool IsClosed();		//�����˳��߼��ж�
	void Clear(float r, float g, float b, float a);		//SDL��մ���
private:
	SDL_Window* m_window;		//���SDL2 window ָ�룬���Ա����������SDL_Window
	SDL_GLContext m_glContext;		//����ϵͳͨ��GLContext����GPU���ƴ���	
	bool m_isClosed;		//�����˳��߼�
};
