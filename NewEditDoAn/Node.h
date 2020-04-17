#pragma once
#include "Vector2.h"
#include <graphics.h>
#include <iostream>
#define COLOR(r,g,b) (0x04000000 | RGB(r,g,b))

using namespace std;

class Node
{
	Vector2 positions;
	int radius = 20;
	int normal1=COLOR(0,194,255);
	//int hl1=RED;
	int hl1=COLOR(236,180,80);
	int out_color=COLOR(255,162,0);
	int blue_color=COLOR(130,133,255);
	int purple_color=COLOR(198,0,255);
	int value;
	int index;
	int distance = INT_MAX;
	Node* parrent = nullptr;


	public:
		Node(Vector2 positions, int value);
		void draw_normal();
		void draw_hl();
		void draw_blue();
		void draw_yellow();
		Vector2 get_position();
		void inti(Vector2 positions,int value);
		int get_value();
		void set_value(int value);
		bool concomitant(int left,int right,int bot,int top);
		bool is_clicked(int x,int y);
		void set_position(int x,int y);
		void set_index(int index);
		int get_index();
		void set_parrent(Node * parren);
		Node* get_parrent();

		void set_distance(int distance);
		int get_distance();
		

		
		Node();
		~Node();
	
		
};

