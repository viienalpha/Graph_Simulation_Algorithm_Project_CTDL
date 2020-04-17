#include "Button.h"
#include <graphics.h>

Button::Button(Vector2 position,Vector2 size,string text)
{
	this->position=position;
	this->size=size;
	this->text=text;
}
void Button::init(Vector2 position,Vector2 size,string text)
{
	this->position=position;
	this->size=size;
	this->text=text;
}

void Button::draw_normal()
{
	
	setfillstyle(SOLID_FILL, normal);
	setcolor(normal);
	rectangle(position.x, position.y, position.x + size.x, position.y + size.y);
	floodfill(position.x + 5, position.y + 5, normal);
	setbkcolor(normal);
	setcolor(BLACK);
	settextstyle(BOLD_FONT, 0, 1);
	outtextxy(position.x + size.x / 2 - textwidth(&text[0u]) / 2, position.y + size.y / 2 - textheight(&text[0u]) / 2,
		&text[0u]);
		setcolor(RED);
	rectangle(position.x+2, position.y+2, position.x + size.x-2, position.y + size.y-2);
}

void Button::draw_hl()
{
	setfillstyle(SOLID_FILL, hl);
	setcolor(hl);
	rectangle(position.x, position.y, position.x + size.x, position.y + size.y);
	floodfill(position.x + 2, position.y + 2, hl);
	setbkcolor(hl);
	setcolor(0);
	settextstyle(BOLD_FONT, 0, 1);
	outtextxy(position.x + size.x / 2 - textwidth(&text[0u]) / 2, position.y + size.y / 2 - textheight(&text[0u]) / 2,
		&text[0u]);
}
void Button::draw_chose()
{
	setfillstyle(SOLID_FILL,chose);
	setcolor(chose);
	rectangle(position.x, position.y, position.x + size.x, position.y + size.y);
	floodfill(position.x + 2, position.y + 2, chose);
	setbkcolor(chose);
	setcolor(0);
	settextstyle(BOLD_FONT, 0, 1);
	outtextxy(position.x + size.x / 2 - textwidth(&text[0u]) / 2, position.y + size.y / 2 - textheight(&text[0u]) / 2,
		&text[0u]);
}

bool Button::is_selected(int mouse_x,int mouse_y)
{
	if(mouse_x>=position.x&&mouse_y>=position.y&&mouse_x<=position.x+size.x&&
	mouse_y<=position.y+size.y)
	{
		return true;
	}

	return false;
	
}
Button::Button(){
}
Button::~Button(){
}
