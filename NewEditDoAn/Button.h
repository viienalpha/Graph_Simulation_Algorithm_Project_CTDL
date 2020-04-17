#pragma once
#include <graphics.h>
#include<string.h>
#include<Windows.h>
#include "Vector2.h"
#define COLOR(r,g,b) (0x04000000 | RGB(r,g,b))
using namespace std;
class Button
{
	Vector2 position;
	Vector2 size;
	string text;
	int normal=COLOR(255, 222, 0);
	int hl=COLOR(255,240,113);
	int chose=COLOR(192,149,0);
	public:
		Button(Vector2 position,Vector2 size,string text);
		void init(Vector2 position,Vector2 size,string text);
		void draw_normal();
		void draw_hl();
		void draw_chose();
		bool is_selected(int mouse_x,int mouse_y);
		Button();
		~Button();
		
};
