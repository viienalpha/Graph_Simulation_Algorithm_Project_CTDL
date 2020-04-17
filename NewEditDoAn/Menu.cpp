#include "Menu.h"
#include "Vector2.h"

Menu::Menu(int maxsize)
{
	this->maxsize=maxsize;
	this->size=0;
	this->buttons=new Button[maxsize];
	this->select=-1;
}

void Menu::addbutton(Vector2 position,Vector2 size,string name)
{
	buttons[this->size].init(position,size,name);
	this->size++;
}
void Menu::draw()
{
	for(int i=0;i<size;i++)
	{
		buttons[i].draw_normal();
	}
}
void Menu::reset_select()
{
	select=-1;
}
int Menu::update()
{
	Vector2 mouse;
	mouse.x = mousex();
	mouse.y = mousey();
	if (mouse.x > 400) {
		return select;
	}
	if (ismouseclick(WM_LBUTTONDOWN))
	{
		clearmouseclick(WM_LBUTTONDOWN);
		for (int i = 0; i < size; i++)
		{
			if (i == select)
			{
				buttons[i].draw_chose();
			}
			else if (buttons[i].is_selected(mouse.x, mouse.y))
			{
				buttons[i].draw_chose();
				select = i;
			}
		}
	}
	else if (ismouseclick(WM_MOUSEMOVE))
	{
		clearmouseclick(WM_MOUSEMOVE);
		for (int i = 0; i < size; i++)
		{
			if (i == select)
			{
				buttons[i].draw_chose();
			}
			else if (buttons[i].is_selected(mouse.x, mouse.y))
			{
				buttons[i].draw_hl();
			}
			else
			{
				buttons[i].draw_normal();
			}
		}
	}

	return select;
}

Menu::~Menu(){
}
