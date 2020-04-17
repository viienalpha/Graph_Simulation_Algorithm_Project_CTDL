#include "Save_file.h"
#define ENTER 13

void Save_file::get_name_from_user()
{
	string i;
	string a="";
	string input="Nhap Ten file: ";
	a=input;
	setbkcolor(BLACK);
	setcolor(WHITE);
	outtextxy(400,15,&a[0u]);
	while(true)
	{
		if(kbhit())
		{
			char inpt=getch();
			if(inpt==ENTER)
			{
				setbkcolor(BLACK);
				setcolor(WHITE);
				outtextxy(400,15,"                                          ");
				current_file="savefile/"+i+".ptit";
				return;
			}
			else if(inpt==8)
			{
				if (!i.empty())
				{
					i.pop_back();
					a.clear();
					a = input + i + "   ";
					setbkcolor(BLACK);
					setcolor(WHITE);
					outtextxy(400, 15, &a[0u]);
				}
			}
			else if (inpt >= 32 &&inpt <= 128 )
			{
				i += inpt;
				a.clear();
				a = input + i + "   ";
				setbkcolor(BLACK);
				setcolor(WHITE);
				outtextxy(400, 15, &a[0u]);
				//outtextxy(400+a.size(), 15, &i[0u]);
			}
		}
	}
}
void Save_file::save_node(ofstream& file,Node node)
{
	file<<node.get_value()<<" ";
	file<<node.get_index()<<" ";
	file<<node.get_position().x<<" ";
	file<<node.get_position().y<<" ";
	file<<endl;
}
void Save_file::save_list_node(ofstream &file,List_node list_node)
{
	for(int i=0;i<list_node.size_return();i++)
	{
		save_node(file,*list_node.get_node()[i]);
	}
}
void Save_file::save_matrix(ofstream &file,int**matrix,int size)
{
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			file<<matrix[i][j]<<" ";
		}
		file<<endl;
	}
}

void Save_file::save(List_node list_node,int **matrix)
{
	ofstream file(current_file);
	int size = list_node.size_return();
	
	file << size << "\n";
	
	save_list_node(file, list_node);
	file << endl;
	save_matrix(file,matrix,size);
	delay(100);
	setbkcolor(BLACK);
	setcolor(WHITE);
	outtextxy(400, 15, "Save Thanh Cong");
	
	
	file.close();
}
Node Save_file::load_node(ifstream& file)
{
	Node node;
	int value,index,x,y;
	file>>value;
	file>>index;
	file>>x;
	file>>y;
	string k;
	getline(file,k); //xun dong
	
	node.set_position(x,y);
	node.set_index(index);
	node.set_value(value);
	return node;
	
}
void Save_file::read_matrix(ifstream &file,int** matrix,int size)
{
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			file>>matrix[i][j];
			std::cout<<matrix[i][j]<<" ";
		}
		std::cout<<endl;
		string b;
		getline(file,b);
	}
}
void Save_file::load_list_node(ifstream& file,List_node* list_node,int size)
{
	for(int i=0;i<size;i++)
	{
		Node node=load_node(file);
		list_node->add_node(node);
	}
	
}
void Save_file::load_file(List_node* list_node,int **matrix)
{
	string b;
	int size;
	ifstream file(current_file);
	
	file>>size;
	load_list_node(file,list_node,size);
	getline(file,b);
	read_matrix(file,matrix,size);
	
	file.close();
}

bool Save_file::is_filename_exist(){
	ifstream file(current_file);
	if(file.is_open() == false){
		return false;
	}
	file.close();
	return true;
}

Save_file::Save_file(){
}
Save_file::~Save_file(){
}



