#include"Layout.h"


void Layout::draw_menuzone(){
	setcolor(border_color);
	rectangle(10,10,width_menu_zone-20,height_menu_zone);

}


void Layout::draw_nodezone()
{
	setcolor(border_color);
	rectangle(width_menu_zone-10,110,WIDTH-20,HEIGHT-20);
}
void Layout::draw_matrixzone()
{
	setcolor(border_color);
	rectangle(10,height_menu_zone+10,width_menu_zone-20,height_menu_zone+280);
}
void Layout::draw_inputzone()
{
	setcolor(border_color);
	rectangle(width_menu_zone-10,10,WIDTH-20,100);
}
void Layout::out_line()
{
	setcolor(line_color);
	rectangle(10,10,width_menu_zone-20,height_menu_zone);
	rectangle(width_menu_zone-10,110,WIDTH-20,HEIGHT-20);
	rectangle(10,height_menu_zone+10,width_menu_zone-20,height_menu_zone+280);
	rectangle(width_menu_zone-10,10,WIDTH-20,100);
	rectangle(2, 2, WIDTH-10, HEIGHT-13);
}
void Layout::window_zone()
{

	draw_menuzone();
	draw_matrixzone();
	draw_nodezone();
	draw_inputzone();
	setcolor(RED);
	rectangle(2, 2, WIDTH-10, HEIGHT-13);
	setfillstyle(SOLID_FILL, RED);
	floodfill(3, 3, RED);
	out_line();
	

}
Layout::Layout(){
}
Layout::~Layout(){
}
