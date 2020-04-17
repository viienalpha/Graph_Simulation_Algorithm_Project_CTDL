#pragma once
#include "List_node.h"
#include "List_Arrow.h"
#include "Layout.h"
#include "Save_file.h"
#include <queue>
#include <stack>
#define GRAPH_H

class Graph
{
	
	stack<Node*> save_thutu;
	Node* from=NULL;
	Node* to=NULL;
	int max=20;
	int size=0;
	bool visited[20];
	int **matrix=0;
	List_node *list_node;
	Layout *layout;
	List_node *list_node_2;
	List_Arrow *list_arrow;
	int dem_lt=0;
	string reset_printed="                                   ",otext_tplt="";
	int delete_node=-1;
	bool after_duyet=false;
	bool flag_tplt=false,flag_dinhtru=false,flag_canhcau=false,flag_dfs=false;
	//endl cho dfs and tplt
	int endl=15,tab=395;
	
	int auto_name = 0;
	
public:
	
	//kiemtra do thi
	bool do_thi_rong();
	//outtext do thi rong
	void outtext_dothirong();
	
	//getkeyboard
	int nhap_trongso();
	void fill_screen();

	void add_node();
	void add_arrow();
	void delete_one_node();
	void delete_matrix(int position);
	void delete_all();
	void move_node();
	void help();
	void draw();	
	bool full();
	
	//reset
	void reset_visited();
	void reset_print();
	//thuat toan
	//dfs
	void start_dfs();
	void DFS(Node* start);
	void DFS_dequy(Node* start);
	//bfs
	void start_bfs();
	void BFS(Node* start);
	
	//topo
	void topo_sort();
	
	//dinhtru
	void dinh_tru();
	
	//canhcau
	void canh_cau();
	
	//tplt
	void trans_matrix();
	int tplt();
	
	//bellman
	void bellman_ford();

	
	//flag
	void reset_flag();
	bool find_click_first_node();
	
	//file
	void save_file();
	void read_file();
	
	//exit
	void exit();
	
	Graph();
	~Graph();
};


