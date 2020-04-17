#ifndef SAVE_FILE_H
#define SAVE_FILE_H
#include "Node.h"
#include "List_node.h"
#include <string>
#include <fstream>
class Save_file
{
	std::string list_file_name[100];
	int size = 0;
	std::string current_file;
	
public:
	void get_name_from_user();

	void save_node(ofstream& file,Node node);
	void save_list_node(ofstream &file, List_node list_node);
	void save_matrix(ofstream &file, int**matrix,int size);
	void save(List_node list_node, int **matrix);


	Node load_node(ifstream& file);
	void read_matrix(ifstream &file,int** matrix,int size);
	void load_list_node(ifstream& file,List_node* list_node, int size);
	void load_file(List_node* list_node, int **matrix);
	
	bool is_filename_exist(); // kiem tra file co ton tai ko
	
	Save_file();
	~Save_file();
};

#endif
