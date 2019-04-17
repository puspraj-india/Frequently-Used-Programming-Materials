#include<bits/stdc++.h>
using namespace std;

//trie structure
struct trie
{
  trie **arr;
  bool end;
}*root=NULL;

trie* create_node()
{
  trie *temp=new trie;
  temp->arr=new trie*[26];
  for(int i=0;i<26;i++)
  temp->arr[i]=NULL;
  temp->end=0;
  return temp;
}
//insert function
void insert(string s)
{
  int l=s.length();

  //if root is null
  if(root==NULL)
  {
    root=create_node();
    trie* temp=root;
    for(int i=0;i<l;i++)
    {
      temp->arr[s[i]-97]=create_node();
      temp=temp->arr[s[i]-97];
    }
    temp->end=1;
    return;
  }
//if root is not null
  int i=0;
  trie *temp2=root;
  while(temp2->arr[s[i]-97]!=NULL && i<l)
  {
    temp2=temp2->arr[s[i]-97];
    i++;
  }
  if(i==l)
  {
    temp2->end=1;
    return;
  }
  else
  {
    while(i<l)
    {
      temp2->arr[s[i]-97]=create_node();
      temp2=temp2->arr[s[i]-97];
      i++;
    }
    temp2->end=1;
    return;
  }
}

//search function
bool search_word(string s)
{
  if(root==NULL)
  return 0;
  trie*temp=root;
  int i=0,l=s.length();
  while(temp!=NULL && i<l)
  {
    temp=temp->arr[s[i]-97];
    cout<<"yes"<<endl;
    i++;
  }
  if(i==l && temp!=NULL &&temp->end==1)
  {
    cout<<"yes"<<endl;
    return 1;
  }
  else return 0;
}

//main program
int main()
{
  int n;
  cin>>n;
  cin.ignore();
  string s;
  for(int i=0;i<n;i++)
  {
    getline(cin,s);
    insert(s);
  }

  cout<<search_word("puspraj");
  cout<<search_word("shishant");
   cout<<search_word("sujit");
   cout<<search_word("pusp");
   cout<<search_word("puspd");

  return 0;
}
