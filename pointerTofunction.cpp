#include<iostream>
using namespace std;

int add(int a,int b)
{
	return a+b;
}
int sub(int a,int b)
{
	return a-b;
}
int mul(int a,int b)
{
	return a*b;
}
int div(int a,int b)
{
	if(b!=0)
	return a/b;
}

int main()
{
	int (*ptr)(int ,int );
	//cout<<ptr[0](1,2);
	return 0;
}
