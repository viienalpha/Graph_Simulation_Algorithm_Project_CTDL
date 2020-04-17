#include "Program.h"
#include "List_node.h"



void Program::update()
{
	while (true)
	{
		if(kbhit())
		{
			char input =getch();
			if (input == 13)
			{
				graph->reset_print();
				graph->fill_screen();
				graph->draw();

				menu->reset_select();
			
			}
			if(input==27)
			{
				break;
			}
		}
		int action = menu->update();
		
		switch (action)
		{
		case 0:
		{
		
			graph->add_node();
			break;
		}
		case 1:
		{
			
		graph->add_arrow();	
			break;
		}
		case 2:
		{
		
			graph->delete_one_node();
			break;
		}
		case 3:
		{
		
			graph->delete_all();
			menu->reset_select();
			break;
		}
		case 4:
		{
			
			graph->move_node();
			break;
		}
		case 5:
		{
		
			graph->help();
			menu->reset_select();
			break;
		}
		case 6:
		{
		
			graph->start_dfs();
			break;
		}
		case 7:
		{
		
			graph->start_bfs();
			break;
		}
		case 8:
		{
			
			graph->topo_sort();
			menu->reset_select();
			break;
		}
		case 9:
		{
			graph->dinh_tru();
			menu->reset_select();
			break;
		}
		case 10:
		{
			setbkcolor(BLACK);
			setcolor(WHITE);
			outtextxy(400,15,"Code chua hoan thanh");
			outtextxy(400,35,"Enter de tat dinh that");
			break;
		}
		case 11:
		{
			
			graph->canh_cau();
			menu->reset_select();	
			break;
		}
		case 12:
		{
			setbkcolor(BLACK);
			setcolor(WHITE);
			outtextxy(400,15,"Code chua hoan thanh");
			outtextxy(400,35,"Enter de tat euler");
			break;
		}
		case 13:
		{
			graph->bellman_ford();
			break;
		}
		case 14:
		{
			
			graph->tplt();
			menu->reset_select();
			break;
		}
		case 15:
		{
			setbkcolor(BLACK);
			setcolor(WHITE);
			outtextxy(400,15,"Code chua hoan thanh");
			outtextxy(400,35,"Enter de tat hamliton");
			break;
		}
		case 16:
		{
			graph->save_file();
			menu->reset_select();
			break;
		}
		
		case 17:
		{
			graph->read_file();
			menu->reset_select();
			break;
		}
		case 18:
		{
			graph->exit();
			break;
		}
		case 19:
		{
			break;
		}
		
	}

			
	}
}

Program::Program()
{

	menu = new Menu(19);
	menu->addbutton(Vector2(20, 20), Vector2(110, 30), "ADD NODE");
	menu->addbutton(Vector2(140, 20), Vector2(110, 30), "ARROW");
	menu->addbutton(Vector2(260, 20), Vector2(110, 30), "DELETE");
	menu->addbutton(Vector2(20,60),Vector2(110,30),"DEL ALL");
	menu->addbutton(Vector2(140,60),Vector2(110,30),"MOVE NODE");
	menu->addbutton(Vector2(260,60),Vector2(110,30),"HELP");
	menu->addbutton(Vector2(20, 110), Vector2(110, 50), "DFS");
	menu->addbutton(Vector2(140, 110), Vector2(110, 50), "BFS");
	menu->addbutton(Vector2(260, 110), Vector2(110, 50), "TOPO SORT");
	menu->addbutton(Vector2(20, 170), Vector2(110, 50), "DINH TRU");
	menu->addbutton(Vector2(140, 170), Vector2(110, 50), "DINH THAT");
	menu->addbutton(Vector2(260, 170), Vector2(110, 50), "CANH CAU");
	menu->addbutton(Vector2(20, 230), Vector2(110, 50), "EULER");
	menu->addbutton(Vector2(140, 230), Vector2(110, 50), "X->Y");
	menu->addbutton(Vector2(260, 230), Vector2(110, 50), "TPLT");
	menu->addbutton(Vector2(140,290),Vector2(110,50),"HAMILTON");
	menu->addbutton(Vector2(20, 360), Vector2(110, 50), "SAVE");
	menu->addbutton(Vector2(140, 360), Vector2(110, 50), "LOAD");
	menu->addbutton(Vector2(260, 360), Vector2(110, 50), "EXIT");
	menu->draw();
	Layout l;
	l.window_zone();
	graph = new Graph;

}
Program::~Program(){
}
