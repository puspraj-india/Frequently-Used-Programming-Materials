#include<iostream>
using namespace std;
int main()
{
	int a[10],i,j,k;
	cout<<"\nEnter 10 elements in array\t";
	for(i=0;i<10;i++)
	cin>>a[i];
	for(i=0;i<9;i++)
	{
		for(j=0;j<9-i;j++)
		{
			if(a[j]>a[j+1])
			{
				k=a[j];
				a[j]=a[j+1];
				a[j+1]=k;
			}
		}
	}
	cout<<"Sorted array is \t";
	for(i=0;i<10;i++)
	{
		cout<<a[i]<<"  ";
	}
	return 0;
}
