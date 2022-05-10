/*
    g++ drill_1.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"
#include "std_lib_facilities.h"
int main()
{
try
{

using namespace Graph_lib;

Point topleft{100,100};

Simple_window ablak {topleft, 1280,720, "Canvas"};
ablak.set_label("Window");
// Ablak átnevezés


Axis xaxis {Axis::x, Point{40,400}, 300, 10, "x tengely"};
//Axis típusú, x tengely, ami 40,400-nál kezdődik, 300 pixel hosszú, 10 pöcök van rajta, és a neve x tengely
Axis yaxis {Axis::y, Point{40,400}, 300, 10,"y tengely"};
yaxis.set_color(Color::dark_red);
yaxis.label.set_color(Color::blue);

Function sinus {sin,0,100,Point{40,200},1000,50,50};
//Sinus függveny, amit 0-100-as intervallumban értelmezünk, ahol 0,0 a 40,200 értéknél van, 100 pontot rajzolunk ki, és x/y scale =50
sinus.set_color(Color::yellow);
sinus.set_style(Line_style(Line_style::dash,3));

Polygon haromszog;
haromszog.add(Point{300,200});
haromszog.add(Point{350,100});
haromszog.add(Point{400,200});//Felveszem a x pontját a sokszögnek, jelen esetben háromszognek
haromszog.set_style(Line_style(Line_style::dash,5));
//Vonalstílus szaggatott, 5 vastag


Rectangle negyszog {Point{200,200}, 100, 50};
//200,200 pontban a bal felső sarka, 100 széles, 50 magas
negyszog.set_fill_color(Color::red);

Closed_polyline poly_rect;
poly_rect.add(Point{100,150});
poly_rect.add(Point{200,150});
poly_rect.add(Point{200,200});
poly_rect.add(Point{100,200});
poly_rect.add(Point{50,175});
 //Felveszek x pontot, amit összekötök
poly_rect.set_fill_color(Color::green);


Text szoveg (Point{300,300},"Gvaz");
szoveg.set_font_size(40);


Image pingu {Point{600,400},"pingu.jpg"};
//Hol van a kép bal felső sarka, mi a neve
Circle kor {Point{400,400},50};
//400, 300 potnban a középpont, 50 a sugár
Ellipse ellip {Point{400,400}, 75,25};

Mark kozep {Point{400,400},'x'};



ablak.attach(kor);
ablak.attach(ellip);
ablak.attach(kozep);
ablak.attach(pingu);
ablak.attach(szoveg);
ablak.attach(poly_rect);
ablak.attach(negyszog);
ablak.attach(haromszog);
ablak.attach(sinus);
ablak.attach(xaxis);
ablak.attach(yaxis);
// Ezzel teszem fel az alakzatot
ablak.wait_for_button();
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

