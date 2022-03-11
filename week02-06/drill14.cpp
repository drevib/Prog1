#include <iostream>
#include <string>

using namespace std;

class B1{
    public:
    virtual void vf(){cout << "B1::vf()\n";} // at lesz irva, a fuggveny szamit ra
    void f() {cout << "B1::f()\n";}
    virtual void pvf() = 0;  		     // tisztan virtualis fuggveny, absztrakt fuggveny -> no implementation 
					     // absztrakt osztaly + deriving == no work
};

class D1 : public B1{
    public:
        virtual void vf(){cout << "D1::vf()\n";}
        void f() {cout << "D1::f()\n";}
        //virtual void pvf() = 0; 
};

class D2 : public D1{
    public:
        void pvf() {cout << "D2::pvf()\n";}  // virtualis fuggveny atirva, erteket kap == not abstract == works
					     // D2 class != abstract == works 
};

class B2{
    public:
        virtual void pvf()=0;
};

class D21 : public B2{
    public:
        string s;
        void pvf() {cout << s << "\n";}
};

class D22 : public B2{
    public:
        int i;
        void pvf() {cout << i << "\n";}
        void f(B2& b2bref) {b2bref.pvf();} 
};

int main(){
    /*
    B1 b1;
    b1.vf();
    b1.f();
    cout<<"---\n";

    D1 d1;
    d1.vf();
    d1.f();
    cout<<"---\n";

    B1& bref = d1;  // gets non-virtual B1 not d1 
    bref.vf();
    bref.f();
    cout<<"---\n";*/

    D2 d2;
    d2.f();
    d2.vf();
    d2.pvf();
    cout<<"---\n";

    D21 d21;
    d21.s = "D21::pvf()";
    d21.pvf();
    cout<<"---\n";
    //last drill !!!
    D22 d22;
    d22.i = 10;
    d22.f(d21);
    d22.f(d22);
}