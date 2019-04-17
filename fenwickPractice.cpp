#include<iostream>
#include<vector>
using namespace std;
vector<long long> tree(100001);

void update(int i,int x,int n)
{
  while(i<=n)
  {
    tree[i]+=x;
    i+=i&-i;
  }
}

long long range(int a)
{
  long long sum=0;
  while(a>0)
  {
    sum+=tree[a];
    a-=a&-a;
  }
  return sum;
}

int main()
{
  for(int i=0;i<100001;i++)
  tree[i]=0;
  long n,x,q,a,b,t;
  long long sum=0;
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>x;
    update(i,x,n);
  }
  cin>>q;
  for(int i=0;i<q;i++)
  {
    cin>>t>>a>>b;
    if(t==1)
    {
      update(a,b,n);
    }
    else
    {
      sum=range(a-1);
      //cout<<"Sum "<<sum<<endl;
      int l=a,r=n;
      int temp=0,flag=0;
      long long tempsum=0;
      int mid=(l+r)/2;
      while(l<=r)
      {
        tempsum=range(mid);
        //cout<<"tempsum "<<tempsum<<endl;
        if(tempsum-sum>b)
        {
          temp=mid;
          r=mid-1;
        }
        else if(tempsum-sum<b)
        {
          l=mid+1;
        }
        else
        {
          temp=mid;
          flag=1;
          //cout<<"here"<<endl;
          break;
        }
        mid=(l+r)/2;
      }
      //cout<<temp<<endl;
      if(flag==0&&temp==0) cout<<-1<<endl;
      else cout<<(temp-a+1)<<endl;
    }
  }
  return 0;
}
