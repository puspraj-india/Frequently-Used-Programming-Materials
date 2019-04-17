//Single source shortest path best formula for all types nodes either positive or negative, only valid for DAG graphs

#include<bits/stdc++.h>
using namespace std;
bool visited[50];
int top[50];
int shortest[50];
int radix;
void topsort(vector<pair<int,int>> *v,int start)
{
  if(visited[start])return;
  int size=v[start].size();
  visited[start]=1;
  for(int i=0;i<size;i++)
  {
    topsort(v,v[start][i].first);
  }
  top[radix]=start;
  radix--;
}

void sssp(vector<pair<int,int>> *v,int start,int n)
{
  shortest[start]=0;
  for(int j=0;j<=n;j++)
  {
    start=top[j];
    for(int i=0;i<v[start].size();i++)
    {
      if(shortest[v[start][i].first]>shortest[start]+v[start][i].second)
      {
        shortest[v[start][i].first]=shortest[start]+v[start][i].second;
      }
    }
  }
  cout<<endl<<endl;
  for(int i=0;i<=n;i++)
  {
    cout<<shortest[i]<<" ";
  }
}

int main()
{
int n,e,s,d,w;
cout<<"Enter the number of nodes\t";
cin>>n;

vector<pair<int,int>> v[n];
cout<<"Enter the number of edges\t";
cin>>e;
for(int i=0;i<e;i++)
{
  cin>>s>>d>>w;
  v[s].push_back(make_pair(d,w));
}
radix=n-1;
topsort(v,0);
radix=0;
for(int i=0;i<n;i++)shortest[i]=1e7;
sssp(v,0,n-1);
for(int i=0;i<n;i++)
{
  cout<<top[i]<<" ";
}
return 0;
}
