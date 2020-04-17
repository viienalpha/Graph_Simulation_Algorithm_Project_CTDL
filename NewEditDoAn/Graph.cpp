#include "Graph.h"
#include <string>
#define ENTER 13
HWND hwnd;

Graph::Graph()
{
	this->list_node = new List_node(30);
	this->list_arrow = new List_Arrow(40);
	this->layout= new Layout();
	matrix=new int*[20];
	
	for (int j = 0; j < max; j++)
	{
		matrix[j] = new int[20];
		for (int k = 0; k < max; k++)
		{
			matrix[j][k] = 0;
		}
	}

}
bool Graph::do_thi_rong()
{
	if(size==0)
	{
		return true;
	}
	return false;
	

}

void Graph::outtext_dothirong()
{
	setbkcolor(BLACK);
	setcolor(WHITE);
	outtextxy(400,15,"Do Thi Rong");
}

bool Graph::full()
{
	return size==max;
}

int Graph::nhap_trongso()
{
	int x = from->get_position().x + (((to->get_position().x - from->get_position().x) / 2))/2;
	int y = from->get_position().y + (((to->get_position().y - from->get_position().y) / 2))/2;
	string i ;
	string a = "";
	setbkcolor(BLACK);
	setcolor(WHITE);
	string question = "Nhap Trong So :   ";
	a = question + "   ";
	outtextxy(400, 15, &a[0u]);
	while(true)
	{
		if(kbhit())
		{
			char inpt = getch();
			if(inpt==ENTER)
			{
				setbkcolor(BLACK);
				outtextxy(400-2, 15,"                              ");
				int trongso=atoi(i.c_str());
				//std::cout<<trongso<<"\n";
				return trongso;
			}
			else if (inpt == 8)
			{
				if (!i.empty())
				{
					i.pop_back();
					a.clear();
					a = question + i + "   ";
					setbkcolor(BLACK);
					setcolor(WHITE);
					outtextxy(400, 15, &a[0u]);
				}
			}
			else if(inpt=='-'&&i.size()<2||inpt>='0'&&inpt<='9'&&i!="--"&&i[1]!='-'&&i.size()<2)
			{
				i += inpt;
				a.clear();
				a =question+ i +"   ";
				setbkcolor(BLACK);
				setcolor(WHITE);
				outtextxy(400, 15,&a[0u]);
				setbkcolor(BLACK);
				setcolor(WHITE);
				outtextxy(x, y, &i[0u]);
		
			}

		}

	}


}
void Graph::reset_print()
{
	setbkcolor(BLACK);
	setfillstyle(SOLID_FILL, BLACK);
	rectangle(400-9,11,1280-19,101);
	floodfill(400, 12, RED);
	setbkcolor(BLACK);
	//Layout().window_zone();
}
void Graph::fill_screen()
{
	setbkcolor(BLACK);
	
	//setfillstyle(HATCH_FILL, BLACK);
	setcolor(BLACK);
	//rectangle(11,11,399,419);
	setfillstyle(SOLID_FILL, BLACK);
	rectangle(391,112,1280-21,720-21);
	floodfill(410, 200, RED);
	setbkcolor(BLACK);
	setfillstyle(SOLID_FILL, BLACK);
	rectangle(11,420+11,400-21,420+279);
	floodfill(12, 420+12, RED);
	setbkcolor(BLACK);
	rectangle(400-10,10,1280-20,100);
	floodfill(400, 12, RED);
	setbkcolor(BLACK);
	Layout().window_zone();
	
}

void Graph::draw()
{
	
	list_arrow->draw_all_arrow();
	list_node->draw_all_node();
	int x = 20;
	int y =440;	 ;
	//int colorr = RGB(119, 255, 0);
	{
		setbkcolor(BLACK);
		settextstyle(0, 0, 2);
		for (int i=0; i < size; i++)
		{
			for (int j =0; j < size; j++)
			{
				if(matrix[i][j]<=10)
				{
					string temp= std::to_string(matrix[i][j])+" ";
					setcolor(WHITE);
					outtextxy(x, y, &temp[0u]);
				}
				string s = std::to_string(matrix[i][j]);
				if(size>10)
				{
					setbkcolor(BLACK);
					outtextxy(20, 440, "   ");
					setfillstyle(SOLID_FILL, BLACK);
					rectangle(11,420+11,400-21,420+279);
					floodfill(12, 420+12, RED);
					setbkcolor(BLACK);
					outtextxy(x+10, y+90, "Khong the hien thi");				
				}
				else if(size<=10)
				{
					setcolor(WHITE);
					outtextxy(x, y, &s[0u]);
					x += 35;
				}
				}
				if(size<=10)
					{
						x = 20;
						y += 20;
					}
		}
			settextstyle(BOLD_FONT, 0, 3);
	
	}
		
	
	
}

void Graph::add_node()
{
		if (mousex() < 400||mousex()>1220||mousey()<125||mousey()>695)
		{
			return;
		}
	if(full())
	{
			return;
	}
	if (ismouseclick(WM_LBUTTONDOWN))
	{
		clearmouseclick(WM_LBUTTONDOWN);
		Vector2 position;
		position.x = mousex();
		position.y = mousey();
		
		if (list_node->is_existed(position.x - 20, 40, 40, position.y - 20) == false)
		{
			Node new_node(position, auto_name++);
			list_node->add_node(new_node);
			size++;
			list_node->draw_all_node();
			draw();
		}
	}
	
	
}
void Graph::add_arrow()
{
	if(mousex()<400)
	{
		return;
	}
	if(find_click_first_node()==true)
	{
		from->draw_hl();
		while(ismouseclick(WM_LBUTTONDOWN))
		{
			clearmouseclick(WM_LBUTTONDOWN);
			to=list_node->find_is_click_node(mousex(),mousey());
			if(to!=NULL)
			{
			
				to->draw_hl();
				
				list_arrow->add_arrow(new Arrow(from,to,0));
				draw();
				int trong_so=nhap_trongso();
				
				std::cout<<from->get_index();
				std::cout<<"\n"<<to->get_index();
				matrix[from->get_index()][to->get_index()]=trong_so;
				
				list_arrow->get_last_arrow()->set_trongso(trong_so);
				
				draw();
				from->draw_normal();
				to->draw_normal();
				
				from=NULL;
				to=NULL;
				break;
			}
			else
			{
				from->draw_normal();
				to=NULL;
			}
			
		}
	}
	
}
void Graph::delete_one_node()
{
	if(mousex()<400)
	{
		return;
	}
	if(find_click_first_node())
	{
		list_arrow->delete_arrow(from,matrix);
		delete_matrix(from->get_index());
		list_node->delete_node(from);
		from=nullptr;
		fill_screen();
		Layout().window_zone();
		draw();
	}
}
void Graph::delete_matrix(int position)
{
	for(int i=position;i<size-1;i++)
	{
		for(int j=0;j<size;j++)
		{
			matrix[i][j]=matrix[i+1][j];
		}
	}
	for(int i=0;i<size-1;i++)
	{
		for(int j=position;j<size-1;j++)
		{
			matrix[i][j]=matrix[i][j+1];
		}
	}
	for(int i=0;i<size;i++)
	{
		matrix[size-1][i]=0;
	}
	for(int i=0;i<size;i++)
	{
		matrix[i][size-1]=0;
	}
	size--;
}
void Graph::delete_all()
{
	if(size==0)
	{
		{
		setbkcolor(BLACK);
		setcolor(WHITE);
		outtextxy(400, 15,"DO THI RONG");
		delay(200);
		outtextxy(400,15,"                   ");
		
		}
	}
	else
	{
	string b;
	string a="";
	string question = "Ban co that su muon xoa(Y/N) :   ";
	a = question + "   ";
	setbkcolor(BLACK);
	setcolor(WHITE);
	outtextxy(400, 15, &a[0u]);
	
	
	while(true)
	{
	if(kbhit())
		{
			char inpt = getch();
			if(inpt==ENTER)
			{
				if(b=="y")
				{				
				setbkcolor(BLACK);
				outtextxy(400-2, 15,"                                                 ");
				list_arrow->delete_all_arrow();
				list_node->delete_all_node();
				for(int i=0;i<size;i++)
					{
						for(int j=0;j<size;j++)
							{
									matrix[i][j]=0;
							}
					}
				size=0;
				auto_name=0;
				fill_screen();	
				Layout().window_zone();
				break;
				}
				else if(b=="n")
				{
				outtextxy(400-2, 15,"                                                 ");
				break;
				}
			
			}
			else if(inpt=='n'||inpt=='y'&&b.size()<2)
			{
				b += inpt;
				a.clear();
				a =question+b +"   ";
				setbkcolor(BLACK);
				setcolor(WHITE);
				outtextxy(400, 15,&a[0u]);
			}

		}

	}
	}
}
void Graph::move_node()
{
	static bool moving = false;

	if (mousex() < 410||mousex()>1240||mousey()<130||mousey()>680)
	{
		return;
	}
	
	if(!moving){
	
		if (find_click_first_node() == false)
		{
			return;
		}
		else
		{
			clearmouseclick(WM_LBUTTONUP);
			moving = true;
		}
	}
	else{
		
		from->set_position(mousex(),mousey());
	
		fill_screen();
	//	list_node->draw_all_node();
	//	list_arrow->delete_all_arrow();
		draw();
		if(ismouseclick(WM_LBUTTONUP)){
			clearmouseclick(WM_LBUTTONUP);
			moving= false;
			from = nullptr;
		}
	}
}
	


void Graph::help()
{


	setbkcolor(BLACK);
	setcolor(WHITE);
	reset_print();
	outtextxy(600, 15,"Chuong trinh demo Do thi co huong co trong so");
	outtextxy(400, 35,"Cach su dung:");
	outtextxy(400, 55,"Phim <ESC> : Thoat Chuong Trinh");
	outtextxy(900, 55,"Phim <Enter> : Thoat Chuc Nang");
	outtextxy(400,75,"ENTER De Tat Huong Dan");
 	//while(true)
 //	{
   //if(kbhit())
		{
		//	char inpt = getch();
		//	if(inpt==ENTER)
		//	{
				//fill_screen();
				//outtextxy(500, 15,"                                                            ");
			//	outtextxy(400, 35,"                                                  ");
			//	outtextxy(400, 55,"                                                  ");
			//	outtextxy(800, 55,"                                         ");
			//	outtextxy(400,75,"                                                  ");
			//	break;
		//	}
			
				
			
		}
//	}
	return;
}
bool Graph::find_click_first_node()
{
	if (from != NULL)
	{
		return true;
	}
	if (ismouseclick(WM_LBUTTONDOWN))
	{
		clearmouseclick(WM_LBUTTONDOWN);
		from = list_node->find_is_click_node(mousex(), mousey());
	}
	if (from != NULL)
	{
		return true;
	}
	else
	{
		return false;

	}
}

//thuat toan
void Graph::reset_visited()
{
	for(int i=0;i<size;i++)
	{
		if(i==delete_node)
		{
			visited[i]=true;
		}
		else
		{
		visited[i]=false;
		}
	}
}
void Graph::start_dfs()
{
	if(do_thi_rong()==true)
	{
		outtext_dothirong();
		return;
	}

	setbkcolor(BLACK);
	setcolor(WHITE);
	if(after_duyet==false)
	{
	outtextxy(400,15,"Chon Dinh Bat Dau");
	}

	if (mousex() < 400)
	{
		return;
	}
	if (find_click_first_node())
	{
		outtextxy(400,15,"                     ");
		reset_visited();
		DFS(from);
		after_duyet=true;
		from = nullptr;
		outtextxy(400,35,"Enter de hoan thanh");
		while (!kbhit)
			{
			}
	}
}
void Graph::DFS(Node* start)
{

	bool printed[20];
	for (int i = 0; i < 20; i++)
	{
		printed[i] = false;
	}
string	outtex,otext_tplt;
stack<Node*> stack;
stack.push(start);
visited[start->get_index()]=true;
while(!stack.empty())
{
	
	Node* curr=stack.top();
	stack.pop();
	if(flag_tplt==false)
	{
	curr->draw_hl();
	}
	//	
	if(flag_dinhtru==false&&flag_canhcau==false)
		{
	if (!printed[curr->get_index()])
	{
		
		
			if(flag_tplt==true)
			{
				setbkcolor(BLACK);
				setcolor(WHITE);
				otext_tplt = otext_tplt + std::to_string(curr->get_index()) + ",";
				outtextxy(tab,endl,"(") ;outtextxy(tab+10,endl,&otext_tplt[0u]);
				if(tab==395)
				{
					curr->draw_blue();
				}
				if(tab==465)
				{
					curr->draw_yellow();
				}
				if(tab==535)
				{
						curr->draw_hl();
				}
				if(tab==605)
				{
					curr->draw_normal();	
				}
			}
			else
			{
				setbkcolor(BLACK);
				setcolor(WHITE);
				string a=std::to_string(curr->get_index());
				outtex=outtex+a+"->";
				outtextxy(400,15,&outtex[0u]);
			}
		
		
	printed[curr->get_index()] = true;
	}
	}
	//
	for(int i=0;i<size;i++)
	{
		if(!visited[i]&&matrix[curr->get_index()][i]!=0)
		{
			visited[i]=true;
			stack.push(list_node->get_node()[i]);
			stack.push(curr);
		}
		
	}
	if(flag_dinhtru==false&&flag_canhcau==false)
	{
	delay(400);
	}
}
if(flag_dinhtru==false&&flag_canhcau==false)
{

	if(flag_tplt==false)
	{
		outtex.pop_back();
		outtex.pop_back();
		outtex+=" hoan thanh";
		outtextxy(400,15,&outtex[0u]);
	}
	if(flag_tplt==true)
	{
		setbkcolor(BLACK);
		setcolor(WHITE);
		otext_tplt.pop_back();
		otext_tplt+=")";
		outtextxy(tab+10,endl,&otext_tplt[0u]);
		tab+=70;
		if(tab>1200)
		{
			endl+=20;
			tab=395;
		}
	}
}
}
void Graph::DFS_dequy(Node* start)
{
	visited[start->get_index()]=true;
	for(int i=0;i<size;i++)
	{
		if(!visited[i]&&matrix[start->get_index()][i]!=0)
		{
			DFS_dequy(list_node->get_node()[i]);
		}
	}
	save_thutu.push(start);
}

//bfs

void Graph::start_bfs()
{
	if(do_thi_rong()==true)
	{
		outtext_dothirong();
		return;
	}
	setbkcolor(BLACK);
	setcolor(WHITE);
	if(after_duyet==false)
	{
	outtextxy(400,15,"Chon Dinh Bat Dau");
	}

	if (mousex() < 400)
	{
		return;
	}
	if (find_click_first_node())
	{
		outtextxy(400,15,"                     ");
		reset_visited();
		BFS(from);
		after_duyet=true;
		from = nullptr;
		outtextxy(400,35,"Enter de hoan thanh");
		while (!kbhit)
			{
				
			}
	}
}

void Graph::BFS(Node* start)
{
	string outtex;
	queue<Node*> queue;
	queue.push(start);
	visited[start->get_index()]=true;
	while(!queue.empty())
	{
		Node*current=queue.front();
		current->draw_hl();
		queue.pop();
		setbkcolor(BLACK);
		setcolor(WHITE);
		string a=std::to_string(current->get_index());
		outtex=outtex+a+"->";
		outtextxy(400,15,&outtex[0u]);
		for(int i=0;i<size;i++)
		{
			if(!visited[i]&& matrix[current->get_index()][i]!=0)
			{
				visited[i] = true;
				queue.push(list_node->get_node()[i]);	
			}
		
		}
		delay(1000);
	}
	outtex.pop_back();
	outtex.pop_back();
	outtex+=" hoan thanh";
	outtextxy(400,15,&outtex[0u]);
}

//topo

void Graph::topo_sort()
{
	if(do_thi_rong()==true)
	{
		outtext_dothirong();
		return;
	}
	string outtex="";
	reset_visited();
	for(int i=0;i<size;i++)
	{
		if(!visited[i])
		{
			// lay thu tu hoan thanh dfs cua tung node
			DFS_dequy(list_node->get_node()[i]);
			
		}
	}
	while(!save_thutu.empty())
	{
		save_thutu.top()->draw_hl();
		outtex+= std::to_string(save_thutu.top()->get_index()) + "->";
		setbkcolor(BLACK);
		setcolor(WHITE);
		outtextxy(400, 15, &outtex[0u]);
		save_thutu.pop();
		delay(500);
	}
	outtex.pop_back();
	outtex.pop_back();
	outtex+=" hoan thanh";
	outtextxy(400,15,&outtex[0u]);
	outtextxy(400,35,"Enter de hoan thanh");
}


//dinhtru
void Graph::dinh_tru()
{
	if(do_thi_rong()==true)
	{
		outtext_dothirong();
		return;
	}
	int dem=0;
	string c_dinhtru="Dinh tru la: ";
	reset_visited();
	vector<int> temp;
	flag_dinhtru=true;
	int ban_dau=tplt();
	reset_visited();
	for(int i=0;i<size;i++)
	{
		delete_node=i;
		int c=tplt();
		if(c>ban_dau)
		{
			temp.push_back(i);
		}
		delete_node=-1;
		reset_visited();
		
	}
	for(int i=0;i<temp.size();i++)
	{
	c_dinhtru=c_dinhtru+std::to_string(temp[i])+" ";
		list_node->get_node()[i]->draw_yellow();
		delay(200);
		dem++;
	}
	setbkcolor(BLACK);
		setcolor(WHITE);
		if(dem==0)
		{
		//	outtextxy(400,15,"                               ");
			outtextxy(400,15,"Do Thi Khong Co Dinh Tru");
		}
		else
		{
		
		outtextxy(400,15,&c_dinhtru[0u]);
		}
		outtextxy(400,35,"Enter de hoan thanh");
	reset_flag();
}

//canhcau
void Graph::canh_cau()
{
	if(do_thi_rong()==true)
	{
		outtext_dothirong();
		return;
	}
	int dem=0;
	flag_canhcau=true;
	string a="Canh cau la: ";
	reset_visited();
	vector<int> dau;
	vector<int> duoi;
	int ban_dau=tplt();
	reset_visited();
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			if(matrix[i][j]!=0)
			{
				int matrix_bandau=matrix[i][j];
				matrix[i][j]=0;
				int c=tplt();
				if(c>ban_dau)
				{
					dau.push_back(i);
					duoi.push_back(j);
					dem++;
				}
				matrix[i][j]=matrix_bandau;
			}
			
		}
	}
	for(int i=0;i<dau.size();i++)
	{
		a=a+"("+std::to_string(dau[i])+","+std::to_string(duoi[i])+")";
		for(int j=0;j<size;j++)
		{
		Arrow(list_node->get_node()[dau[i]],list_node->get_node()[duoi[i]],matrix[i][j]).draw_arrow_hl();
		}
	}
	setbkcolor(BLACK);
	setcolor(WHITE);
	if(dem==0)
	{
		outtextxy(400,15,"Do Thi Khong Co Canh Cau");
	}
	else
	{
	outtextxy(400,15,&a[0u]);
	}
	reset_flag();
}

//tplt
void Graph::trans_matrix()
{
	int matrix_temp[20][20];
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			matrix_temp[i][j]=matrix[i][j];
		}
	}
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			matrix[i][j]=matrix_temp[j][i];
		}
	}
}
int Graph::tplt()
{
if(do_thi_rong()==true)
	{
		outtext_dothirong();
		return 0;
	}
	flag_tplt=true;
	int dem=0;
	reset_visited();
	for(int i=0;i<size;i++)
	{
		if(!visited[i])
		{
			DFS_dequy(list_node->get_node()[i]);
		}
	}
	reset_visited();
	trans_matrix();
	while(!save_thutu.empty())
		{
			Node*current =save_thutu.top();
			save_thutu.pop();
			if(visited[current->get_index()]==false)
			{
				DFS(current);
				dem++;
			}
		
		}
		
			setbkcolor(BLACK);
			setcolor(WHITE);
			string d = "co " + std::to_string(dem) + " thanh phan lien thong";
			if (dem == 0)
			{
				d = "do thi rong";
			}
			if(flag_dinhtru==false&&flag_canhcau==false)
			{
			outtextxy(400, endl+20, &d[0u]);
			outtextxy(400, endl+40, "Enter de hoan thanh");
			}
		
			
		
	trans_matrix();
		
	if(flag_dinhtru==false&&flag_canhcau==false)
	{	
	reset_flag();
	}
	
	endl=15;
	return dem;
}
//bellman

void Graph::bellman_ford()
{
	if(do_thi_rong()==true)
	{
		outtext_dothirong();
		return;
	}
	string i;
	if(mousex()<400)
	{
		return;
	}
	if(find_click_first_node()==true)
	{
		from->draw_yellow();
		while(ismouseclick(WM_LBUTTONDOWN))
		{
			clearmouseclick(WM_LBUTTONDOWN);
			to=list_node->find_is_click_node(mousex(),mousey());
			if(to!=NULL)
			{
				to->draw_yellow();
				from->set_distance(0);
				for(int c=0;c<size-1;c++)
				{
					for(int i=0;i<size;i++)
					{
						for(int j=0;j<size;j++)
						{
							if(matrix[i][j]!=0)
							{
								Node* u=list_node->get_node()[i];
								Node* v=list_node->get_node()[j];
								if(u->get_distance()!=INT_MAX&&u->get_distance()+matrix[i][j]<v->get_distance())
								{
									v->set_distance(u->get_distance()+matrix[i][j]);
									v->set_parrent(u);
								}
							}
						}
					}
				}
				
				//reset
				for(int i=0;i<size;i++)
				{
					list_node->get_node()[i]->set_distance(INT_MAX);
				}
				if(to->get_parrent()==nullptr)
				{
					outtextxy(400, 15, "khong co duong di");
					outtextxy(400,35,"Enter de hoan thanh");
					from = NULL;
					to = NULL;
					return;
				}
				//in duong di
				stack<Node*> paths;
				while(to->get_parrent()!=nullptr)
				{
					paths.push(to);
					to=to->get_parrent();
					
					
				//delay(1000);
				}
				i+=std::to_string(to->get_index())+"->";
				to->draw_hl();
				delay(500);

				while(paths.empty() == false)
				{
					setbkcolor(BLACK);
					setcolor(WHITE);
					i+=std::to_string(paths.top()->get_index())+"->";
					outtextxy(400,15,&i[0u]);
					paths.top()->draw_hl();
					paths.pop();
					delay(500);
				}
				
				
				i.pop_back();
				i.pop_back();
				i+="        ";
				setbkcolor(BLACK);
					setcolor(WHITE);
				outtextxy(400,15,&i[0u]);
				outtextxy(400,35,"Enter de hoan thanh");
				//to->draw_yellow();
				from=nullptr;
				from=NULL;
				to=NULL;
				break;
				
			}
			else
			{
				from->draw_normal();
				to=NULL;
			}
		}
	}
}



//flag
void Graph::reset_flag()
{
	flag_tplt=false;
	flag_dinhtru=false;
	flag_canhcau=false;
	flag_dfs=false;
}
//file
void Graph::save_file()
{
	if(do_thi_rong()==true)
	{
		outtext_dothirong();
		return;
	}
	Save_file save_file;
	save_file.get_name_from_user();
	save_file.save(*list_node,matrix);
}
void Graph::read_file()
{
	Save_file s;
	s.get_name_from_user();
	
	if(s.is_filename_exist() == false){
		// thong bao loi
		outtextxy(400,15,"File khong ton tai");
		return;
	}
	
	list_node->delete_all_node();
	list_arrow->delete_all_arrow();
	s.load_file(list_node,matrix);
	size=list_node->size_return();
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			if(matrix[i][j]!=0)
			{
				Node * start=list_node->get_node()[i];
				Node * end=list_node->get_node()[j];
				Arrow* arrow=new Arrow(start,end,matrix[i][j]);
				list_arrow->add_arrow(arrow);
			}
		}
	}
	fill_screen();
	draw();
	
	
}

//exit
void Graph::exit()
{
	string b;
	string a="";
	string question = "Ban co that su muon thoat chuong trinh (Y/N) :   ";
	a = question + "   ";
	setbkcolor(BLACK);
	setcolor(WHITE);
	outtextxy(400, 15, &a[0u]);
	
	
	while(true)
	{
	if(kbhit())
		{
			char inpt = getch();
			if(inpt==ENTER)
			{
				if(b=="y")
				{				
				closegraph();
				break;
				}
				else if(b=="n")
				{
				outtextxy(400-2, 15,"                                                 ");
				break;
				}
			
			}
			else if(inpt=='n'||inpt=='y'&&b.size()<2)
			{
				b += inpt;
				a.clear();
				a =question+b +"   ";
				setbkcolor(BLACK);
				setcolor(WHITE);
				outtextxy(400, 15,&a[0u]);
			}

		}
	}
	
	
}


Graph::~Graph(){
}
