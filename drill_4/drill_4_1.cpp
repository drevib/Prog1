//g++ drill_4_1.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill_4_1 `fltk-config --ldflags --use-images`

#include "Simple_window.h"
#include "Graph.h"
#include "std_lib_facilities.h"

double one(double x) {return 1;}
double slope(double x) { return x/2;}
double square(double x) { return x*x;}
double sloping_cos(double x) {return cos(x)+slope(x);}

int main()
{
	try
	{
		using namespace Graph_lib;
		int constexpr xmax =600; int constexpr ymax =600;
		Point topleft{100,100};
		Simple_window ablak(topleft, xmax,ymax, "Function Graphs");
		
		
		constexpr int Origox=xmax/2; constexpr int Origoy=ymax/2;
		Point origo{Origox,Origoy};
		constexpr int xlength=400;   constexpr int ylength=400;


		Axis x{Axis::x,Point{100,Origoy},xlength,20,"1=20 pixels"};
		x.set_color(Color::red);
		Axis y{Axis::y,Point{Origox,ylength+100},ylength,20,"1=20 pixels"};
		y.set_color(Color::red);
		ablak.attach(x); 
		ablak.attach(y); //Axis eddig
		
		
		constexpr int r_min=-10; constexpr int r_max=11;
		constexpr int xscale=20; constexpr int yscale=20;
		constexpr int points=400; 

		Function konstans{one,r_min,r_max,origo,points,xscale,yscale};
		Function linear{slope,r_min,r_max,origo,points,xscale,yscale,}; Text label{Point{100,Origoy+85},"x/2"};
		Function parabola{square,r_min,r_max,origo,points,xscale,yscale}; 
		Function cosinus{cos,r_min,r_max,origo,points,xscale,yscale}; cosinus.set_color(Color::blue);
		Function coslinear{sloping_cos,r_min,r_max,origo,points,xscale,yscale};
		
		ablak.attach(konstans);
		ablak.attach(linear); ablak.attach(label);
		ablak.attach(parabola); //Függvények
		ablak.attach(cosinus);
		ablak.attach(coslinear);








		ablak.wait_for_button();

	}

catch(exception& e)
{
cerr << "error: " << e.what() << '\n'; 
keep_window_open();
return 1;
}
catch(...)
{
cerr << "Unknown Expcetion." << '\n'; 
keep_window_open();
return 2;
}
}
