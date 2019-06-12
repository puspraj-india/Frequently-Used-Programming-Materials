#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

class Fenwick
{
  vector<int> v;
  int siz;
public:
  Fenwick(int n)
  {
    siz=(int)(ceil(log(10000)/log(2)));
    v.resize((1<<siz)+1);
  }

  //Point Update
  void update(int index)
  {
    int range=1<<siz;
    while(index<=range)
    {
      v[index]+=1;
      index+=index&-index;
    }
  }
  //Point Query
  int query(int index)
  {
    int sum=0;
    while(index>0)
    {
      sum+=v[index];
      index-=index&-index;
    }
    return sum;
  }

  //The solution of fenwick search is of O(logn) here we don't need any binary search or query for finding the answer, using bit concept we can obtain answer
  //Very effieient algorithm for finding the answer
  int FenwickSearch(int k)
  {
    int ans=-1;
    int x=1<<siz,temp=0;
    while(x>0)
    {
      if(v[temp+x]>=k)
      {
        ans=temp+x;
      }
      if(v[temp+x]<k)
      {
        k=k-v[temp+x];
        temp+=x;
      }
      x=x>>1;
    }
    return ans;
  }
};


int main()
{
  int n,x;
  cin>>n;
  Fenwick obj(n);
  for(int i=0;i<n;i++)
  {
    cin>>x;
    obj.update(x);
  }
  int q;
  cout<<"Enter the number of queries\t";
  cin>>q;
  int k;
  for(int i=0;i<q;i++)
  {
    cin>>k;
    cout<<obj.FenwickSearch(k);
  }
}
