#pragma once
#include "Button.h"

class Menu
{
	Button *buttons;
	int size;
	int maxsize;
	int select = -1;

public:
	Menu(int maxsize);
	~Menu();
	void addbutton(Vector2 position, Vector2 size, string name);
	void draw();
	void reset_select();
	int update();
	
};
