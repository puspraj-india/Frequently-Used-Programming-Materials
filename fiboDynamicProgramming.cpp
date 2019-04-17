#include<iostream>
using namespace std;

int fibo(int n,int a[])
{
	if(n==1||n==2)
	return 1;
	if(a[n]!=0)
	return a[n];
	int result= fibo(n-1,a)+fibo(n-2,a);
	a[n]=result;
	return result;
}

int main()
{
	int n;
	cin>>n;
	int a[n]={0};
	cout<<fibo(n,a);
}
