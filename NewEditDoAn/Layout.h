#pragma once
#include<graphics.h>
#define HEIGHT 720
#define WIDTH 1280
#define COLOR(r,g,b) (0x04000000 | RGB(r,g,b))


class Layout
{
	int border_color=RED; //  
	int line_color= COLOR(255,210,0);
	int width_menu_zone=400;
	int height_menu_zone= 420;
	int width_draw_zone=800;
	int bar_color=COLOR(130,0,154);
	public:
		void draw_menuzone();
		void draw_nodezone();
		void draw_matrixzone();
		void draw_inputzone();
		void window_zone();
		void out_line();
		Layout();
		~Layout();

};
