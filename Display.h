#pragma once		//头文件只包含一次
//用于SDL2显示窗口的类

#include <iostream>
using namespace std; 

#include"SDL2\SDL.h"

class Display
{
public:
	Display(int width, int height, const string& title);		//窗口宽高以及标题
	~Display();

	void Update();//双重缓存机制-->事件处理
	bool IsClosed();		//程序退出逻辑判断
	void Clear(float r, float g, float b, float a);		//SDL清空窗口
private:
	SDL_Window* m_window;		//添加SDL2 window 指针，可以避免添加整个SDL_Window
	SDL_GLContext m_glContext;		//操作系统通过GLContext操作GPU绘制窗口	
	bool m_isClosed;		//控制退出逻辑
};
