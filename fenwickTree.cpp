#include<iostream>
#include<vector>
using namespace std;

void insert(int i,vector<int> &v,int val)
{
  int v_size=v.size();
  while(i<v_size)
  {
    v[i]+=val;
    i+=i&-i;
  }
}
void traverse(vector<int> v)
{
  for(int i=1;i<v.size();i++)
  {
    cout<<v[i]<<" ";
  }
}

int range(int i,const vector<int> &v)
{
  int sum=0;
  while(i>0)
  {
    sum+=v[i];
    i-=i&-i;
  }
  return sum;
}
int main()
{
  int n,x;
  cin>>n;
  vector<int> fenwick(n+1);
  for(int i=0;i<=fenwick.size();i++)
  fenwick[i]=0;
  for(int i=1;i<=n;i++)
  {
    cin>>x;
    insert(i,fenwick,x);
  }
int l,k,r;
cin>>k;
for(int i=0;i<k;i++)
{
  cin>>l>>r;
  cout<<range(r,fenwick)-range(l-1,fenwick)<<endl;
}
  return 0;
}
