#include<iostream>
using namespace std;
struct bst
{
	int data;
	bst* right;
	bst* left;
}*root=NULL;
bst* getBst(int item)
{
	bst *temp = new bst;
	temp->data=item;
	temp->right=NULL;
	temp->left=NULL;
	return temp;
}
void insert()
{
	int n;
	bool flag;
	cout<<"\nEnter the element to be inserted\t";
	cin>>n;
	bst *temp=getBst(n);
	if(root==NULL)
	{
		root=temp;
		return;
	}
	bst *temp2=root;
	bst* temp3=root;
	while(temp2!=NULL)
	{
	if(temp->data<=temp2->data)
	{
		temp3=temp2;
		temp2=temp2->left;
		flag = true;
	}
	else 
	{
		
		temp3=temp2;
		temp2=temp2->right;
		flag=false;
	}
}
	if(flag==true)
	{
		temp3->left=temp;
		return;
	}
	else 
	{
		temp3->right=temp;
		return;
	}
	
	
}

void inorder(bst *root)
	{
		if(root==NULL)
		return;
		inorder(root->left);
		cout<<root->data<<"  ";
		inorder(root->right);
	}
	
int height(bst* root)
{
	if(root==NULL)
	{
		return -1;
	}
	int a=height(root->left);
	int b=height(root->right);
	if(a>b)
	return a+1;
	else
	return b+1;
	}	
int main()
{
	insert();
	insert();
	insert();
	insert();
	insert();
	insert();
	inorder(root);
	cout<<endl<<height(root);
	return 0;
	
}
