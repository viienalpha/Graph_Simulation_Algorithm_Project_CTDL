#include "List_Arrow.h"

List_Arrow::List_Arrow(int maxsize)
{
	this->maxsize=maxsize;
	this->size=0;
	this->arrow=new Arrow*[maxsize];
}
void List_Arrow::add_arrow(Arrow* new_arrow)
{
	arrow[size]=new_arrow;
	size++;
}
void List_Arrow::draw_all_arrow()
{
	for(int i=0;i<size;i++)
	{
		arrow[i]->draw_arrow_normal();
	}
}

Arrow* List_Arrow::get_last_arrow(){
	return arrow[size-1];
}

void List_Arrow::delete_arrow(Node* node,int **matrix)
{
	for(int i=0;i<size;)
	{
		if(arrow[i]->get_from()==node)
		{
			matrix[node->get_index()][arrow[i]->get_to()->get_index()];
			delete_arrow_at(i);
		}
		else if(arrow[i]->get_to()==node)
		{
			matrix[arrow[i]->get_from()->get_index()][node->get_index()];
			delete_arrow_at(i);	
		}
		else
		{
			i++;
		}
	}
}
void List_Arrow::delete_arrow_at(int position)
{
	delete arrow[position];
	for(int i=position;i<size-1;i++)
	{
		arrow[i]=arrow[i+1];
	}
	size--;
}
void List_Arrow::delete_all_arrow()
{
	for(int i=0;i<size;i++)
	{
		delete arrow[i];
	}
	size=0;
}
List_Arrow::List_Arrow(){
}
List_Arrow::~List_Arrow()
{
}
