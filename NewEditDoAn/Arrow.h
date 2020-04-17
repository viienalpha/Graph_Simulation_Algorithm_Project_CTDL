#ifndef ARROW_H
#define ARROW_H
#include <graphics.h>
#include "Node.h"
#include "Vector2.h"

class Arrow
{
	Node* from;
	Node* to;
	int normal_color=COLOR(0,194,255);
	int hl_color=COLOR(144,0,255);
	int trongso=0;
	
	public:
		Arrow(Node* from,Node* to,int trongso);
		void draw_muiten(int x1, int y1, int x2, int y2, int color);
		void draw_arrow_normal();
		void draw_arrow_hl();
		void set_trongso(int trongso);
		int get_trongso();
		Node* get_from();
		Node* get_to();
		Arrow();
		~Arrow();
};

#endif
