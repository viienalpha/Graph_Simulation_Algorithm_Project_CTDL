#pragma once
#include "Menu.h"
#include"Layout.h"
#include"Node.h"
#include"Graph.h"
class Program
{
	Menu *menu;
	Graph* graph;
	public:
		void update();
		Program();
		~Program();
};

