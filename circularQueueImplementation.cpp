#include<iostream>
#define size 5
int q[size];
int front=-1,rear=-1;
using namespace std;

int insert(int n)
{
	
	if((rear+1)%size==front)
	return -1;
	if(front==-1)
	{
		front=0;
		rear=0;
	}
	else
	rear=(rear+1)%size;
	
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
	int z=q[front];
	front=(front+1)%size;
	return z;
}

int traverse()
{
	int f=front,r=rear;
	if(front==-1)
	return -1;
	if(front==rear)
	cout<<q[front];
	while(f!=r)
	{
		cout<<q[f]<<" ";
		f=(f+size+1)%size;
	}
	cout<<q[f];
}

int search(int n)
{
	int f=front,r=rear;
	if(front==-1)
	return-1;
	if(n==q[front])
	return 1;
	while(f!=r)
	{
		if(q[f]==n)
		return 1;
		f=(f+size+1)%size;
	}
	if(q[r]==n) return 1;
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
			w=insert(n);
			if(w==-1)
			cout<<"Queue is full";
			break;
		case 2:
			y=del();
			if(y==-1)
			cout<<"Queue is empty";
			else cout<<"The deleted element is "<<y;
			break;
		case 3:
			w=traverse();
			if(w==-1) cout<<"Queue is empty";
			break;
		case 4:
			cout<<"Enter the element to be searched in the queue\t";
			cin>>n;
			if(front==-1)
			cout<<"empty";
			else
			 {
			 x=search(n);
			if(x==-1) cout<<"Not found";
			else cout<<"found";
		}
			break;
		default:
			break;
	}
}while(choice!=5);
}
