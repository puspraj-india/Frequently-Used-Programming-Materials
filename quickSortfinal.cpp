#include<iostream>
using namespace std;
int Pindex(int a[],int l,int r)
{
	int pivot=a[r],temp;
	int p=l;
	for(int i=l;i<r;i++)
	{
		if(a[i]<=pivot)
		{
			temp=a[p];
			a[p]=a[i];
			a[i]=temp;
			p++;
			
		}
	}
	temp=a[r];
	a[r]=a[p];
	a[p]=temp;
	return p;
}
void quick_sort(int a[],int l,int r)
{
	
	if(l<r)
	{
		int	p=Pindex(a,l,r);
		quick_sort(a,l,p-1);
		quick_sort(a,p+1,r);
	}
}
int main()
{
	int n,i;
	cout<<"\nEnter the number of elements in array\t";
	cin>>n;
	int a[n];
	cout<<"\nEnter the elements of array \t";
	for(i=0;i<n;i++)
	cin>>a[i];
	quick_sort(a,0,n-1);
	cout<<"\nArray after sorting is \t";
	for(i=0;i<n;i++)
	cout<<a[i]<<"   ";
}
