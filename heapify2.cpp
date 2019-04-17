#include <bits/stdc++.h>
using namespace std;

void buildheap(int a[],int i,int size)
{
    int l=2*i,largest;
    int r=2*i+1;
    if(l<=size && a[l]>a[i])
    largest=l;
    else
    largest=i;
    if(r<=size && a[r]>a[largest])
    {
        largest=r;
    }
    if(i!=largest)
    {
        int temp=a[largest];
        a[largest]=a[i];
        a[i]=temp;
        buildheap(a,largest,size);
    }
}

int main() {
	
	int x;
	int n;
	cin>>n;
	int a[n+1];
	for(int i=1;i<=n;i++)
	{
	    cin>>a[i];
	}
	for(int i=n/2;i>=1;i--)
	buildheap(a,i,n);
	
	for(int i=1;i<=n;i++)
	{
	    cout<<a[i]<<"  ";
	}
	return 0;
}

