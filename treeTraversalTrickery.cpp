#include<bits/stdc++.h>
using namespace std;

vector<int>*adj,fenwick,value,preorder[2];
vector<bool>visited;

int n,number=1;


void update(int index,int delta)
{
  while(index<=2*n)
  {
    fenwick[index]+=delta;
    index+=index&-index;
  }
}
int query(int index)
{
  int sum=0;
  while(index>0)
  {
    sum+=fenwick[index];
    index-=index&-index;
  }
  return sum;
}

void initialize(int n)
{
  ::n=n;
  adj=new vector<int>[n];
  visited.resize(n,0);
  value.resize(n,0);
  preorder[0].resize(n,0);
  preorder[1].resize(n,0);
  fenwick.resize(2*n+1,0);
  //fenwick.resize(2*n+1,0);
}

void dfs(int node)
{
  visited[node]=1;
  //preorder.push_back(node);
  update(number,value[node]);
  preorder[0][node]=number++;
  for(int i=0;i<adj[node].size();i++)
  {
    if(visited[adj[node][i]]==0)
    {
      //fenwick[]=number++;
      dfs(adj[node][i]);
    }
  }
  //preorder.push_back(node);
  preorder[1][node]=number++;
}

void takeIP()
{
  int s,d;
  cout<<"Enter the value associated with each node\t";
  for(int i=0;i<n;i++)
  {
    cin>>value[i];
  }
  cout<<"Enter the source and destination\t";
  for(int i=1;i<n;i++)
  {
    cin>>s>>d;
    adj[s].push_back(d);
  }
  dfs(0);
}

void showpreorder()
{
  for(int i=0;i<n;i++)
  {
    cout<<preorder[0][i]<<" "<<preorder[1][i]<<endl;
  }
}

int main()
{
  int n,q;
  cin>>n;
  initialize(n);
  takeIP();
  cout<<"Enter the number of query\t";
  cin>>q;
  for(int i=0;i<q;i++)
  {
    cout<<"Enter the node for which you want to find the sum\t";
    cin>>n;
    cout<<(query(preorder[1][n])-query(preorder[0][n]-1))<<endl;
  }
  return 0;
}
