#include "Node.h"


Node::Node(Vector2 positions,int value)
{
	this->positions.x=positions.x;
	this->positions.y=positions.y;
	this->value=value;
}
void Node::draw_normal()
{
	string a = to_string(value);
	setfillstyle(SOLID_FILL,normal1);
	setcolor(normal1);
	circle(positions.x, positions.y, radius);
	floodfill(positions.x+1, positions.y+1, normal1);
	setbkcolor(normal1);
	setcolor(BLACK);
	outtextxy(positions.x-radius/2,positions.y-radius/2,&a[0u]);
	setcolor(out_color);
	circle(positions.x, positions.y, radius-1);
}
void Node::draw_hl()
{
	string a = to_string(value);
	setfillstyle(SOLID_FILL, hl1);
	setcolor(hl1);
	circle(positions.x, positions.y, radius);
	floodfill(positions.x+1, positions.y+1, hl1);
	setbkcolor(hl1);
	setcolor(BLACK);
	outtextxy(positions.x-radius/2,positions.y-radius/2,&a[0u]);
	setcolor(out_color);
	circle(positions.x, positions.y, radius-1);
}
void Node::draw_blue()
{
	string a = to_string(value);
	setfillstyle(SOLID_FILL,blue_color);
	setcolor(blue_color);
	circle(positions.x, positions.y, radius);
	floodfill(positions.x+1, positions.y+1, blue_color);
	setbkcolor(blue_color);
	setcolor(BLACK);
	outtextxy(positions.x-radius/2,positions.y-radius/2,&a[0u]);
	setcolor(out_color);
	circle(positions.x, positions.y, radius-1);
}
void Node::draw_yellow()
{
	string a = to_string(value);
	setfillstyle(SOLID_FILL, purple_color);
	setcolor(purple_color);
	circle(positions.x, positions.y, radius);
	floodfill(positions.x+1, positions.y+1,purple_color);
	setbkcolor(purple_color);
	setcolor(BLACK);
	outtextxy(positions.x-radius/2,positions.y-radius/2,&a[0u]);
	setcolor(out_color);
	circle(positions.x, positions.y, radius-1);
}


Vector2 Node::get_position()
{
	return positions;
}
void Node::set_position(int x,int y)
{
	this->positions.x=x;
	this->positions.y=y;
}
void Node::inti(Vector2 positions, int value)
{
	this->positions.x=positions.x;
	this->positions.y=positions.y;
	this->value=value;
}
int Node::get_value()
{
	return value;
}
void Node::set_value(int value)
{
	this->value = value;
}
bool Node::concomitant(int left,int right,int bot,int top)
{
	
	if (top + bot < positions.y-radius) {
		return false;
	}
	if(top>positions.y+radius){
		return false;
	}
	if (left + right < positions.x-radius) {
		return false;
	}
	if (left > positions.x + radius)
	{	
		return false;
	}
	return true;

	
}
bool Node::is_clicked(int x,int y)
{
	if(positions.x-radius<=x&&positions.x+radius>=x&&positions.y-radius<=y&&positions.y+radius>=y)
	{
		return true;
	}
	return false;
}
void Node::set_index(int index)
{
	this->index=index;
}
int Node::get_index()
{
	return index;
}

void Node::set_distance(int distance)
{
	this->distance=distance;
}
int Node::get_distance()
{
	return distance;
}
Node * Node::get_parrent()
{
	return parrent;
}
void Node::set_parrent(Node * parren)
{
	this->parrent=parren;
}
Node::Node(){
}
Node::~Node(){
}

