//In the below program here are the explanation of the array taken

//par array is taken for storing the parent of each element with reference to power of 2
//depth array is taken for storing the depth of each elemnet considering 0 as root
//adj array is taken for getting the adjency list of the tree edges



#include<bits/stdc++.h>
using namespace std;

vector<int> *adj,*par,depth;
vector<bool> visited;
int n,d;


//Utility Function to assign appropriate memory
void initialize(int n)
{
  ::n=n;
  adj=new vector<int>[n];
  d=log(n)/log(2);
  par=new vector<int>[d+1];
  for(int i=0;i<=d;i++)
  {
    par[i].resize(n,-1);
  }
  depth.resize(n,0);
  visited.resize(n,0);
}

//For filling the parent table
void fillpar()
{
  for(int i=1;i<=d;i++)
  {
    for(int j=0;j<n;j++)
    {
      int mid=par[i-1][j];
      // par[i][j]=par[i-1][par[i-1][j]];
      if(mid!=-1)
      {
        par[i][j]=par[i-1][mid];
      }
    }
  }
}

//It's basically a bfs for making the tree rooted, in this case we're making specifically 0 as a root
void bfs()
{
  visited[0]=1;
  queue<int> q;
  q.push(0);
  while(!q.empty())
  {
    int temp=q.front();
    q.pop();
    for(int i=0;i<adj[temp].size();i++)
    {
      if(!visited[adj[temp][i]])
      {
        q.push(adj[temp][i]);
        visited[adj[temp][i]]=1;
        par[0][adj[temp][i]]=temp;
        depth[adj[temp][i]]=depth[temp]+1;
      }
    }
  }
  fillpar();
}



void takeIP()
{
  int s,d;
  for(int i=1;i<n;i++)
  {
    cin>>s>>d;
    adj[s].push_back(d);
    adj[d].push_back(s);
  }

  //Calling to bfs
  bfs();
}

int walk(int i,int k)
{
  for(int ii=0;ii<=d;ii++)
  {
    if(((1<<ii) &k)>0)
    i=par[ii][i];
  }
  return i;
}


//Function to calculate LCA
int lca(int i,int j)
{
  if(depth[i]>depth[j])
  {
    i=walk(i,depth[i]-depth[j]);
  }
  else if(depth[j]>depth[i])
  {
    j=walk(j,depth[j]-depth[i]);
  }
  if(i==j)return i;
  for(int ii=d;ii>=0;ii--)
  {
    if(par[ii][i]!=par[ii][j])
    {
      i=par[ii][i];
      j=par[ii][j];
    }
  }
  return par[0][i];
}

void showdepth()
{
  for(int i=0;i<n;i++)
  {
    cout<<depth[i]<<" ";
  }
}

void showpar()
{
  for(int i=0;i<n;i++)
  {
    cout<<i<<"\t";
    for(int j=0;j<d;j++)
    cout<<par[j][i]<<" ";
    cout<<endl;
  }
}

int main()
{
  int n;
  cin>>n;
  initialize(n);
  takeIP();
  cout<<lca(3,6);
}
