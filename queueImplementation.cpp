#include<iostream>
#define size 10
using namespace std;
int q[size];
int front=-1,rear=-1;

//insertion
void insert(int n)
{
	if(rear==size-1)
	{
		cout<<"overflow";
		return;
	}
	if(front==-1)
	front=0;
	rear=rear+1;
	q[rear]=n;
}

int del()
{
	
	if(front==-1)
	return -1;
	
	if(front==rear)
	{
		int temp=q[front];
		front=-1;
		rear=-1;
		return temp;
		
	}
	front++;
}

int  traverse()
{
	if(front==-1)
	return -1;
	for(int i=front;i<=rear;i++)
	cout<<q[i]<<"  ";
}

int search(int n)
{
	for(int i=front;i<=rear;i++)
	{
		if(q[i]==n)
		return 1;
	}
	return 0;
}

int main()
{
	int choice,n,x,y,w;
	do
	{
	cout<<"\n1 for insertion\t";
	cout<<"\n2 for deletion\t";
	cout<<"\n3 for traversing\t";
	cout<<"\n4 for searching\t";
	cout<<"\n5 for exit\t";
	cin>>choice;
	switch(choice)
	{
		case 1:
			cout<<"Enter the element to be inserted in the queue\t";
			cin>>n;
			insert(n);
			break;
		case 2:
			y=del();
			if(y==-1)
			cout<<"Queue is empty";
			else cout<<"The deleted element is "<<y;
			break;
		case 3:
			w=traverse();
			if(w==-1)cout<<"Queue is empty";
			break;
		case 4:
			cout<<"Enter the element to be searched in the queue\t";
			cin>>n;
			 x=search(n);
			if(x==0) cout<<"Not found";
			else cout<<"found";
			break;
		default:
			break;
	}
}while(choice!=5);
	
}
