

//g++ drill_2.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`


#include "Simple_window.h"
#include "Graph.h"
#include "std_lib_facilities.h"


int main()
{
try
{
using namespace Graph_lib;

Point topleft{100,100};

Simple_window win{topleft,800,1000,"Definetly not rickroll"};

//Grid

int x_size = win.x_max();
int y_size = win.y_max()-200;
int x_grid = 100;
int y_grid = 100;
Lines racs;

for (int x=x_grid; x<x_size; x+=x_grid)
	racs.add(Point{x,0},Point{x,y_size});
for (int y = y_grid; y<=y_size; y+=y_grid)
	racs.add(Point{0,y},Point{x_size,y});

//Átló
Vector_ref<Rectangle>negyszogek;

for (int i=0; i<=8;i++)
{
	negyszogek.push_back(new Rectangle {Point{i*100,i*100},100,100});
	negyszogek[i].set_fill_color(Color::red);
	win.attach(negyszogek[i]);
}

//Képek
Image big1 {Point{0,400},"200x200.jpg"};
Image big2 {Point{0,600},"200x200.jpg"};
Image big3 {Point{400,0},"200x200.jpg"};

int x1=100; int y1=0;
Image mike {Point{x1,y1},"100x100.jpg"};

win.attach(racs);
win.attach(big1);
win.attach(big);
win.attach(big3);
win.attach(mike);
win.wait_for_button();

while (true)
{
	int randomszam=rand()%4;

	if (randomszam==0 and x1>=100)
		{
		mike.move(-100,0);
		x1-=100;
		}
	else if (randomszam==1 and x1<=700)
		{
		mike.move(100,0);
		x1+=100;
		}
	else if (randomszam==2 and y1>=100)
		{
		mike.move(0,-100);
		y1-=100;
		}
	else if (randomszam==3 and y1<=700)
		{
		mike.move(0,100);
		y1+=100;
		}
	win.wait_for_button();
}
}


catch (exception& e)
{
    cerr << "error: " << e.what() << '\n'; 
	keep_window_open();
    return 1;
}
catch (...)
{
    cerr << "Oops: unknown exception!\n"; 
	keep_window_open();
    return 2;
}
}