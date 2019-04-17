#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;
template <type T>
T add(T a,T b)
{
	return a+b;
}
int main ()
{
	int a=28,b=12,c;
	
	c=add(a,b);
	cout<<" c =\t "<<c;
	return 0;
}
	

