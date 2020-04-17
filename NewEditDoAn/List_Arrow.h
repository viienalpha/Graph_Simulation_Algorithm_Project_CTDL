#ifndef LIST_ARROW_H

#define LIST_ARROW_H
#include "Arrow.h"
class List_Arrow
{
	Arrow **arrow;
	int size;
	int maxsize;
	public:
	List_Arrow(int maxsize);
	void add_arrow(Arrow* new_arrow);
	void draw_all_arrow();
	void delete_arrow(Node* node,int **matrix);
	void delete_arrow_at(int position);
	void delete_all_arrow();
	Arrow* get_last_arrow();
	List_Arrow();
	~List_Arrow();
};

#endif
