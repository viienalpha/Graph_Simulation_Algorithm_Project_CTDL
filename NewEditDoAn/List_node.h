#pragma once
#include "Node.h"
class List_node
{
	Node ** nodes;
	int size;
	int maxsize;
	public:
		Node** get_node();
		List_node(int maxsize);
		void set_node(Node** nodes);
		void add_node(Node new_node);	
		void draw_all_node();
		bool is_existed(int left, int right,int bot,int top);
		void delete_node(Node* node);
		void delete_node_at(int position);
		void delete_all_node();
		int size_return();
		Node* find_is_click_node(int x,int y);
	
	
		
		List_node();
		~List_node();
};


