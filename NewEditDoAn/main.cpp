#include <graphics.h> 
#include "Vector2.h"
#include "Button.h"
#include "Program.h"
#include <string>

#define HEIGHT 720
#define WIDTH 1280
using namespace std;
int main()
{
	
	string x;
	initwindow(WIDTH, HEIGHT);						
	Program p;
	p.update();
	closegraph();

	while(!kbhit()) delay(1);		
	return 0;
}
