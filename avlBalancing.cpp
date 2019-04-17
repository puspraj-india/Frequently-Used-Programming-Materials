//CODE
#include<iostream>
using namespace std;

//Tree structure
struct tree
{
  int item;
  tree*left;
  tree*right;
}*root=NULL;

//Function to create the new tree node
tree* create_node(int item)
{
  tree * temp=new tree;
  temp->left=NULL;
  temp->right=NULL;
  temp->item=item;
  return temp;
}
//function to insert the new node in a tree
void insert(int item)
{
  tree * temp=create_node(item);
  if(root==NULL)
  {
    root=temp;
    return;
  }
  tree *p,*q=root;
  while(q!=NULL)
  {
    p=q;
    if(q->item>item)
    q=q->left;
    else q=q->right;
  }
  if(p->item>item)
  p->left=temp;
  else p->right=temp;
}

//traversing inorder way
void inorder(tree *root)
{
    if(root==NULL)
    return;
    inorder(root->left);
    cout<<root->item<<" ";
    inorder(root->right);
}

//traversing postorder way
void postorder(tree*root)
{
  if(root==NULL)
  return;
  postorder(root->left);
  postorder(root->right);
  cout<<root->item<<" ";
}

//traversing preorder way
void preorder(tree*root)
{
  if(root==NULL)
  return;
  cout<<root->item<<" ";
  preorder(root->left);
  preorder(root->right);
}

//function returns height of the node
int height(tree*root)
{
  if(root==NULL)return -1;
  return max(height(root->left),height(root->right))+1;
}
//function to get balance factor of the current node
int balance(tree*root)
{
  if(root==NULL)return 0;
  return height(root->left)-height(root->right);
}
//function to left rotate the tree node
tree* leftRotation(tree*root)
{
  tree*temp1=root->right;
  tree*temp2=root->right->left;
  root->right=temp2;
  temp1->left=root;
  root=temp1;
  //returning the root so that after rotating node's parent gets new address of the changed root
  return root;
}
//function to right rotate the node
tree* rightRotation(tree*root)
{
  tree*temp2=root->left->right;
  tree*temp1=root->left;
  root->left=temp2;
  temp1->right=root;
  root=temp1;
  //returning the root so that after rotating node's parent gets new address of the changed root
  return root;
}
tree* search(int item,tree*root)
{
  if(root==NULL)
  {
    return NULL;
  }
  if(item>root->item)
  {
    root->right=search(item,root->right);
  }
  else if(item<root->item)
  {
    root->left=search(item,root->left);
  }
  //this below code snippet checks the balancing factor of each node above the searched node
  int bal=balance(root);
  if(abs(bal)>1)
  {
    if(bal<0)
    {
      if(balance(root->right)<0)
      {
        //RR
        //left rotation of the current node
        root=leftRotation(root);
      }
      else
      {
        //RL
        //right rotation of the root->right
        root->right=rightRotation(root->right);
        //left rotation of the root node node
        root=leftRotation(root);
      }
    }
    else
    {
      if(balance(root->left)<0)
      {
        //LR
        //left rotation of root->left
        root->left=leftRotation(root->left);
        //right rotation of root
        root=rightRotation(root);
      }
      else
      {
        //LL case
        //It calls the right rotation of the current node
        root=rightRotation(root);
      }
    }
  }
  //this root is returned so that the parent does not point to previous node, but the updated node
  return root;
}

int main()
{
  int n,x;
  cout<<"Enter the number of elements in BST\t";
  cin>>n;
  for(int i=0;i<n;i++)
  {
    cin>>x;
    //this function inserts a new node in a tree
    insert(x);

    //This function is made to search the current created node. To check the first unbalanced tree
    //This function could be also be called inside the insert function, just for sake of simplicity i've called it here
    root=search(x,root);
  }
  //traversing the tree so as to check the modified tree
  preorder(root);
  cout<<endl;
}
