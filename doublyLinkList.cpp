#include<iostream>
using namespace std;
struct node
{
	int data;
	node*next;
	node*prev;
};
node*head;
node*new_node(int x)
{
	node* temp=new node;
	if(temp==NULL)
	{
		cout<<"overflow";
		return NULL;
	}
	temp->data=x;
	temp->next=NULL;
	temp->prev=NULL;
	return temp;
}
void insert_at_head()
{
	int x;
	cout<<"\nEnter the integer to be inserted\t";
	cin>>x;
	node*temp=new_node(x);
	node*temp2;
	if(temp==NULL)
	{
		return;
	}
	if(head==NULL)
	{
		head=temp;
		return;
	}
	temp->next=head;
	head->prev=temp;
	head=temp;
}
void traverse_head()
{
	if(head==NULL)
	{
		cout<<"\nUnderflow";
		return;
	}
	node*temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<"-->";
		temp=temp->next;
	}
	cout<<"NULL";
}
void traverse_tail()
{
	if(head==NULL)
	{
		cout<<"Underflow";
		return;
	}
		node *temp=head;
	if(temp->next==NULL)
	{
		cout<<temp->data<<"-->NULL";
		return;
	}
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	while(temp!=NULL)
	{
		cout<<temp->data<<"-->";
		temp=temp->prev;
	}
	cout<<"NULL";
}
void delete_at_head()
{
	if(head==NULL)
	{
		cout<<"Underflow";
		return;
	}
	node*temp=head;
	if(temp->next==NULL)
	{
		delete temp;
		head=NULL;
		return;
	}
	node*temp2=temp;
	temp=temp->next;	
	temp=temp->next;
	head=temp;
	delete temp2;
	//alternative way of writing the line 97 and 98 is temp->next>prev=NULL then temp=temp->next;
	//temp->next->prev=NULL;
	/*node*temp2=temp;
	temp->next->prev=NULL;
	head=temp->next;*/
}
void insert_at_tail()
{
	int x;
	cout<<"Enter the node to be inserted\t";
	cin>>x;
	node*temp=new_node(x);
	if(temp==NULL)
	{
		return;
	}
	if(head==NULL)
	{
		head=temp;
		return;
	}
	node*temp2=head;
	while(temp2->next!=NULL)
	{
		temp2=temp2->next;
	}
	temp2->next=temp;
	temp->prev=temp2;
}
int main()
{
	head=NULL;
	int choice=1;
	while(choice !=0)
	{
	cout<<"\nPress 1 for inserting a node at head ";
	cout<<"\nPress 2 for traversing a link list from head";
	cout<<"\nPress 3 for traversing a link list from tail";
	cout<<"\nPress 4 for deleting an element from head";
	cout<<"\nPress 5 for inserting at tail";
	cout<<"\nEnter your choice\t";
	cin>>choice;
	switch(choice)
	{
		case 1:
			insert_at_head();
			break;
		case 2:
			traverse_head();
			break;
		case 3:
			traverse_tail();
			break;
		case 4:
			delete_at_head();
			break;	
		case 5:
			insert_at_tail();
			break;
	}
	
	}
	return 0;
}
