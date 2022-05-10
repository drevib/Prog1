//g++ drill_3.cpp
#include "std_lib_facilities.h"

class B1
{
public:
	virtual void vf()   {cout<<"B1::vf"<<'\n';}
	void f() 	    	{cout<<"B1::f"<<'\n';}
	virtual void pvf()=0; //Csak akkor lehet ezt így beletenni, ha egy alosztályban definiáljuk is a pvf()-et, magában errort ad
};

class  D1 : public B1 
{
public:
	void vf()  override {cout<<"D1::vf"<<'\n';}
	void f() 			{cout<<"D1::f"<<'\n';}
	void pvf() {cout<<"D1::pvf"<<'\n';}
}; 

class D2: public D1
{
public:
	void pvf() override {cout<<"D2::pvf"<<'\n';}
};

class B2
{
public:
	virtual void pvf()=0;
};

class D21: public B2
{
public:
	string text;
	void pvf() override {cout<<text<<'\n';}
};

class D22:public B2
{
public:
	int num;
	void pvf() override {cout<<num<<'\n';}
	void f(B2& b) {b.pvf();}
};


int main()
{
	/*B1 first;
	first.vf();
	first.f(); */ //Mivel van benne egy pure virtual function, ezért nem csinálhatunk az ősosztályból egy példányt.
	
	D1 second;
	second.vf();//A D1:vf() felülírja a B1:vf().et, míg az f() a B1:f() eredményét fogja kiírni
	second.f(); 
	second.pvf();
	
	B1& third {second};
	third.vf(); //Mivel egy B1 referncia objectet inicializáltunk a D1 objektumra, így a vf() felülírja a B1-et, míg az f-et nem, így a B1 f()-je fut le
	third.f(); 

	D2 fourth;
	fourth.vf();
	fourth.f(); //Mivel a D2-nek nincsen f, és vf függvénye, ezért a D2 f és vf függvényét fogja visszaadni.
	fourth.pvf(); //A D2 pvf-je fut le

	D21 fifth;
	fifth.text="Never Gonna give you up";
	D22 sixth;
	sixth.num=69;

	sixth.f(fifth); sixth.f(sixth);


	return 0;
}

