/*
  Author : Puspraj Jaiswal
  Persistent Segment Trees
  here 'first' is like start pointer of all the nodes
  It's index represents the version of the Segment Trees
  l and r are respective the left and the right node of segment tree
  Increment function does updates on segment trees so after each update new segment tree is formed
  init is a function which is used to Initialize the segment tree, here we are assigning the values to the segment tree using the array
  We can use other utility functions as well like 'propagation and update' for achieving lazy propagation.
*/

#include<bits/stdc++.h>
using namespace std;
class node
{
public:
  int data;
  node *l,*r;
  node(node *l=NULL,node *r=NULL,int d=0)
  {
    this->l=l;
    this->r=r;
    data=d;
  }
};
class PersistentSegTree
{
  public:
  vector<node*> first;
  int *left,*right;
  PersistentSegTree(int n,int q,int *arr)
  {
    ///first=new vector<node*>[q+1];
    int temp=4*n+1;
    first.resize(q+1);
    left=new int[temp];
    right=new int[temp];
    for(int i=0;i<temp;i++)
    {
      left[i]=right[i]=0;
    }
    for(int i=0;i<=q;i++)
    first[i]=NULL;
    init(1,0,n-1,arr);

  }

  int query(int index,node * root,int a,int b)
  {
    if(left[index]>b||right[index]<a)
    {
      return INT_MAX;
    }
    if(left[index]>=a and right[index]<=b)
    {
      return root->data;
    }
    int l=query(2*index,root->l,a,b);
    int r=query(2*index+1,root->r,a,b);
    return min(l,r);
  }

  node *init(int index,int a,int b,int *arr)
  {
    if(a==b)
    {
      left[index]=a;
      right[index]=a;
      first[0]=new node(NULL,NULL,arr[a]);
      return first[0];
    }
    int mid=(a+b)/2;
    left[index]=a;
    right[index]=b;
    node*x,*y;
    x=init(2*index,a,mid,arr);
    y=init(2*index+1,mid+1,b,arr);
    first[0]=new node(x,y,min(x->data,y->data));
    return first[0];
  }

  node* increment(int index,int version,node*root,int a,int b,int val)
  {
    if(left[index]>b||right[index]<a)
    {
      first[version]=root;
      return first[version];
    }
    if(left[index]>=a and right[index]<=b)
    {
      first[version]=new node(root->l,root->r,root->data+val);
      return first[version];
    }
    node *le=increment(2*index,version,root->l,a,b,val);
    node* ri=increment(2*index+1,version,root->r,a,b,val);
    first[version]=new node(le,ri,min(le->data,ri->data));
    return first[version];
  }

};

//Here inside main We are using some of the examples for demonstration of how to use this data structure

int main()
{
  int n,q;
  cout<<"Enter the number of nodes in segTree and number of queries ";
  cin>>n>>q;
  int arr[n];
  cout<<"Enter the values of in array\t";
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
  }
  PersistentSegTree obj(n,q,arr);
  cout<<obj.query(1,obj.first[0],1,3);
  obj.increment(1,1,obj.first[0],2,2,5);
  cout<<endl;
  cout<<obj.query(1,obj.first[1],4,4);
  cout<<endl;
}
