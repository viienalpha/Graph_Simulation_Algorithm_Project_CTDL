#include "Arrow.h"
#include <cmath>

Arrow::Arrow(Node* from, Node* to,int trongso)
{
	this->from=from;
	this->to=to;
	this->trongso=trongso;
}
void Arrow::draw_muiten(int x1,int y1,int x2,int y2,int color)
{
	setlinestyle(SOLID_LINE, 0, 2);
	setfillstyle(SOLID_FILL, color);
	int a[8];
	a[0] = x1 + y2 - y1;
	a[1] = y1 + x1 - x2;
	a[2] = x1 - y2 + y1;
	a[3] = y1 - x1 + x2;
	a[4] = x2; a[5] = y2;
	a[6] = a[0]; a[7] = a[1];
	fillpoly(4, a);
}
void Arrow::draw_arrow_normal()
{
	string i;
	int x_trongso = from->get_position().x + (((to->get_position().x - from->get_position().x) / 2))/2;
	int y_trongso = from->get_position().y + (((to->get_position().y - from->get_position().y) / 2))/2;
	//x1y1 xy node from
	//x2y2 xy node to
	int x1= from->get_position().x;
	int y1= from->get_position().y;
	int x2=to->get_position().x;
	int y2=to->get_position().y;
	setcolor(normal_color);
	float corner = atan(float(abs(from->get_position().y - y2)) / abs(x1 - x2));
	float Rsin = 20 * sin(corner);
	float Rcos = 20 * cos(corner);
	int x11 = x1 + Rcos;
	int y11 = y1 + Rsin;
	int x22 = x2 - Rcos;
	int y22 = y2 - Rsin;
	if (x1 > x2)
	{
		x11 = x1 - Rcos;
		x22 = x2 + Rcos;
	}
	if (y1 > y2)
	{
		y11 = y1 - Rsin;
		y22 = y2 + Rsin;
	}
	setlinestyle(SOLID_LINE, 1, 2);
	setcolor(normal_color);
	line(x11, y11, x22, y22);
	draw_muiten(2 * x22 - (x2 + x22) / 2, 2 * y22 - (y22 + y2) / 2, x22, y22, normal_color);
	i=std::to_string(trongso);
	setbkcolor(BLACK);
	setcolor(WHITE);
	if(trongso!=0)
	{
	outtextxy(x_trongso,y_trongso,&i[0u]);
	}
}
void Arrow::draw_arrow_hl()
{
		//x1y1 xy node from
	//x2y2 xy node to
	int x1= from->get_position().x;
	int y1= from->get_position().y;
	int x2=to->get_position().x;
	int y2=to->get_position().y;
	setcolor(hl_color);
	float corner = atan(float(abs(from->get_position().y - y2)) / abs(x1 - x2));
	float Rsin = 20 * sin(corner);
	float Rcos = 20 * cos(corner);
	int x11 = x1 + Rcos;
	int y11 = y1 + Rsin;
	int x22 = x2 - Rcos;
	int y22 = y2 - Rsin;
	if (x1 > x2)
	{
		x11 = x1 - Rcos;
		x22 = x2 + Rcos;
	}
	if (y1 > y2)
	{
		y11 = y1 - Rsin;
		y22 = y2 + Rsin;
	}
	setlinestyle(SOLID_LINE, 1, 2);
	setcolor(hl_color);
	line(x11, y11, x22, y22);
	draw_muiten(2 * x22 - (x2 + x22) / 2, 2 * y22 - (y22 + y2) / 2, x22, y22, hl_color);
}
void Arrow::set_trongso(int trongso)
{
	this->trongso=trongso;
}
int Arrow::get_trongso()
{
	return trongso;
}
Node * Arrow::get_from()
{
	return from;
}
Node * Arrow::get_to()
{
	return to;
}

Arrow::Arrow()
{
}
Arrow::~Arrow()
{
}
