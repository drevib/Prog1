#include "./GUI/Simple_window.h"
#include "./GUI/Graph.h"

#include <string>
#include <iostream>

using namespace Graph_lib;

// Drill 13

int main()
try {
    

   
    const Point tl {100, 100};
    Simple_window win {tl, 800, 1000, "Chapter 13 Drill"};
    win.wait_for_button();

    int x_size = 800;
    int y_size = 800;
    int x_grid = 100;
    int y_grid = 100;

    Lines grid;
    for (int x = x_grid; x < x_size; x += x_grid)	
        grid.add(Point{x, 0}, Point{x, y_size});    
    for (int y = y_grid; y < y_size; y += y_grid)	
        grid.add(Point{0, y}, Point{x_size, y});	

    grid.set_color(Color::red);

    win.attach(grid);
    win.wait_for_button();

    Vector_ref<Rectangle> rect;
    for (int i = 0; i < x_size; i += x_grid) 
    {
        rect.push_back(new Rectangle{Point{i,i}, Point{i+x_grid,i+x_grid}});
        rect[rect.size() - 1].set_color(Color::invisible);
        rect[rect.size() - 1].set_fill_color(Color::red);
        win.attach(rect[rect.size() - 1]);
    }

    win.wait_for_button();

    Image img1 {Point{0,300}, "./img.jpg"};
    Image img2 {Point{300,600}, "./img.jpg"};
    Image img3 {Point{500,100}, "./img.jpg"};

    win.attach(img1);
    win.attach(img2);
    win.attach(img3);
    win.wait_for_button();

    Image pingu {Point{0,0}, "./pingu.jpg"};
    win.attach(pingu);
    win.wait_for_button();

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            pingu.move(100, 0);
            win.wait_for_button();
        }
        pingu.move(-700, 100);          
        win.wait_for_button();
    }
}
catch(exception& e) {
    cerr << "exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    cerr << "error\n";
    return 2;
}
