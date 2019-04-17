//Single source shortest path best formula for all types nodes either positive or negative, only valid for DAG graphs

#include<bits/stdc++.h>
using namespace std;
bool visited[50];
int top[50];
int shortest[50];
int radix;
void topsort(vector<int> *v,int start)
{
  if(visited[start])return;
  int size=v[start].size();
  visited[start]=1;
  for(int i=0;i<size;i++)
  {
    topsort(v,v[start][i]);
  }
  top[radix]=start;
  radix--;
}

sssp(vertex<int> *v,int start,int n)
{
  shortest[start]=0;
  for(int j=0;j<=n;j++)
  for(int i=0;i<v[start].size();i++)
  {
    if()
  }
}

int main()
{
int n,e,s,d,w;
cout<<"Enter the number of nodes\t";
cin>>n;

vector<int> v[n];
cout<<"Enter the number of edges\t";
cin>>e;
for(int i=0;i<e;i++)
{
  cin>>s>>d;
  v[s].push_back(d);
}
radix=n-1;
topsort(v,0);
index=0;
for(int i=0;i<n;i++)shortest[i]=1e7;
sssp(v,0,n-1);
for(int i=0;i<n;i++)
{
  cout<<top[i]<<" ";
}
return 0;
}
