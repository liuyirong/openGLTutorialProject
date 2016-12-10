#pragma once
#include <iostream>
using namespace std; 

#include"SDL2\SDL.h"

class Display
{
public:
	Display(int width, int height, const string& title);
	~Display();

	void Update();//双重缓存机制-->事件处理
	bool IsClosed();
	void Clear(float r, float g, float b, float a);
private:
	SDL_Window* m_window;
	SDL_GLContext m_glContext;
	bool m_isClosed;//控制退出逻辑
};
