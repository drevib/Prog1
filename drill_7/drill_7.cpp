//g++ drill_7.cpp -o drill_7
#include "std_lib_facilities.h"

template<typename Iter1, typename Iter2>
Iter2 m_copy(Iter1 f1, Iter1 e1, Iter2 f2)
{
	for (auto i=f1;i!=e1; i++)
		{
		*f2=*i;
		f2++;
		}
		return f2;
};
int main()
{
	int a[10]=  {0,1,2,3,4,5,6,7,8,9};
	vector<int>v{0,1,2,3,4,5,6,7,8,9};
	list<int>l  {0,1,2,3,4,5,6,7,8,9};
	cout<<"Base numbers: "<<"{0,1,2,3,4,5,6,7,8,9}"<<endl;
	
	int a2[10]; m_copy(begin(a),end(a),begin(a2));
	vector<int>v2=v;
	list<int>l2=l; //Ezek lesznek a base konténerek lényegében
	
	cout<<"Increased array: ";
	for (auto& x: a)
		{
		x+=2;
		cout << x <<' ';
		} 
		cout<<endl; //Azért hogy normálisan nézzen ki konzolban

	cout<<"Increased list: ";
	for (auto& x: l)
		{
		x+=3;
		cout << x <<' ';
		} 
		cout<<endl;
	
	cout<<"Increased vector: ";
	for (auto& x: v)
		{
		x+=5;
		cout << x <<' ';
		} 
		cout<<endl;
	
	cout<<"Copied increased array into base(second) vector: ";
	m_copy(begin(a),end(a),begin(v2)); //Átmásolom a már növelt tömbböl, az alap vectorba
	for (auto x: v2)
		cout<<x<<' '; cout<<endl;

	cout<<"Copied increased list into base(second) array: ";
	m_copy(l.begin(),l.end(),begin(a2)); //Átmásolom a már növelt listát, az alap tömbbe
	for (auto x: a2)
		cout<<x<<' '; cout<<endl;

	int element1=3, element2=27;  //Első és második keresett elem
	auto elem1=find(v.begin(),v.end(),element1); //Megkeresem melyik memóriacímen van amit keresek
	if (elem1!=v.end()) //Ha nincs benne az adott konténerben
		cout<<element1<< " is at "<<distance(v.begin(),elem1)<<" index."<<endl;
	else
		cout<<element1<<" is not in increased the vector."<<endl;

	auto elem2=find(l.begin(),l.end(),element2);
	if (elem2!=l.end())
		cout<<element2<< " is at "<<distance(l.begin(),elem2)<<" index."<<endl;
	else
		cout<<element2 <<" is not in increased the list."<<endl;

	return 0;
}

