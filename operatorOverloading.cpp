#include<iostream>
using namespace std;
class A
{
	int a;
	int b;
	public:
		A()
		{
			a=0,b=0;
		}
		A(int a)
		{
			this->a=a;
			b=0; 
		}
		A(int a,int b)
		{
			this->a=a;
			this->b=b;
		}
		A operator +(A obj)
		{
			A temp;
			temp.a = obj.a+a;
			temp.b=obj.b+b;
			return temp;
		}
		void show()
		{
			cout<<a<<"  "<<b;
		}
};
int main()
{
	A obj1,obj2(1,1),obj3(2,2);
	obj1=obj2+obj3;
	obj1.show();
	return 0;
	
}
