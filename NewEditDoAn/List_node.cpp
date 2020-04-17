#include "List_node.h"


List_node::List_node(int maxsize)
{
	this->maxsize = maxsize;
	this->nodes = new Node*[maxsize];
	this->size = 0;
}

void List_node::add_node(Node new_node)
{
	nodes[size]=new Node;
	*nodes[size]=new_node;
	nodes[size]->set_index(size);
	size++;
}
int List_node::size_return()
{
	return size;
}
void List_node::draw_all_node()
{
	
	for(int i=0;i<size;i++)
	{
		nodes[i]->draw_normal();
	}
}

bool List_node::is_existed(int left,int right,int bot,int top)
{
	for(int i;i<size;i++)
	{
		if(nodes[i]->concomitant(left,right,bot,top))
		return true;
	}
	return false;
}
void List_node::delete_node(Node* node)
{
	for(int i=0;i<size;i++)
	{
		if(node==nodes[i])
		{
			delete_node_at(i);
		}
	}
}
void List_node::delete_node_at(int position)
{
	delete nodes[position];
	for(int i=position;i<size-1;i++)
	{
		nodes[i]=nodes[i+1];
		nodes[i]->set_index(i);
	}
	size--;
}
void List_node::delete_all_node()
{
	for(int i=0;i<size;i++)
	{
		delete nodes[i];
	}
	size=0;
}
Node * List_node::find_is_click_node(int x,int y)
{
	for(int i=0;i<size;i++)
	{
		if(nodes[i]->is_clicked(x,y)==true)
		{
			return nodes[i];
		}
	}
	return nullptr;
	
}
Node** List_node::get_node()
{
	return nodes;	
}
void List_node::set_node(Node** nodes)
{
	this->nodes=nodes;
}
List_node::List_node(){
}
List_node::~List_node()
{}

