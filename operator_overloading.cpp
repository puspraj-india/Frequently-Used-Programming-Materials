#include<iostream>
using namespace std;
class A
{
	public:
	int a;
	int b;
	public:
		void show()
		{
			cout<<"\na = "<<a;
			cout<<"\nb = "<<b;
		}
		A operator ++(int i)
		{
			a++;
			b++;
		}
		void get(int x,int y)
		{
			a=x;
			b=y;
		}
		int operator [](int n)
		{
			if(n==1)
			return a;
			if(n==2)
			return b;	
		}
		friend ostream& operator <<(ostream &coutt,const A & obj)
		{
			coutt<<"a = "<<obj.a;
			coutt<<"b = "<<obj.b;
			return coutt;
		}
};
int main()
{
	A obj;
	obj.get(1,1);
	obj++;
	obj.show();
	cout<<"Raj = "<<obj[2];
	cout<<"\n\n";
	cout<<obj;
	return 0;
}
