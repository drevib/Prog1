//drill16

#include "./GUI/Lines_window.h"
#include "./GUI/Graph.h"
int main()
{
	try
	{
		Lines_window ablak {Point{100,100},1000,800,"lines"};
		return gui_main();
	}	
catch (exception&e)
{
	cerr<<"error: "<<e.what()<<'\n';
	return 1;
}
catch(...)
{
	cerr<<"Unknow error."<<'\n';
	return 2;
}
}
