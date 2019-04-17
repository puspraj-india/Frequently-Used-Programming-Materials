#include<iostream>
#include<limits>
using namespace std;
//template<typename T>
struct segTree
{
  int *maximum,*minimum,*delta;
  int *left,*right;
  segTree(int n)
  {
    int p=n;
    n=4*n+1;
    maximum = new int[n];
    minimum=new int[n];
    delta=new int[n];
    left=new int[n];
    right=new int[n];
    for(int i=0;i<n;i++)
    {
      maximum[i]=minimum[i]=delta[i]=left[i]=right[i]=0;
    }
    init(1,1,p);
  }
  void init(int index,int a,int b)
  {
    if(a==b)
    {
      left[index]=right[index]=a;
      return;
    }
    left[index]=a;
    right[index]=b;
    int mid=(a+b)/2;
    init(2*index,a,mid);
    init(2*index+1,mid+1,b);
  }

  void increment(int index,int a,int b,int val)
  {
    //    [a--------b]  [l-------r]
    if(left[index]>b||right[index]<a)
    {
      return;
    }
    if(a<=left[index] && b>=right[index])
    {
      delta[index]+=val;
      return;
    }
    propagation(index);
    increment(2*index,a,b,val);
    increment(2*index+1,a,b,val);
    update(index);
  }
  void update(int index)
  {
    minimum[index]=min(minimum[2*index]+delta[2*index],minimum[2*index+1]+delta[2*index+1]);
    maximum[index]=max(maximum[2*index]+delta[2*index],maximum[2*index+1]+delta[2*index+1]);
  }

  void propagation(int index)
  {
    delta[2*index]+=delta[index];
    delta[2*index+1]+=delta[index];
    delta[index]=0;
  }
  int mini(int index,int a,int b)
  {
    //  [a---------b] [l----------r]
    if(left[index]>b||right[index]<a)
    return INT32_MAX;
    if(a<=left[index]&&b>=right[index])
    return delta[index]+minimum[index];
    propagation(index);
    int l=mini(2*index,a,b);
    int r=mini(2*index+1,a,b);
    update(index);
    return min(l,r);
  }

  int maxi(int index,int a,int b)
  {
    //  [l-----------r]  [a----superset-----------b]
    if(a>right[index]||b<left[index])
    return -INT32_MAX;
    if(a<=left[index]&&b>=right[index])
    return maximum[index]+delta[index];
    propagation(index);
    int l=maxi(2*index,a,b);
    int r=maxi(2*index+1,a,b);
    update(index);
    return max(l,r);
  }

void traverse(int n)
{
  for(int i=0;i<4*n+1;i++)
  {
    cout<<"["<<left[i]<<","<<right[i]<<"] =\t "<<maximum[i]<<" "<<minimum[i]<<" "<<delta[i]<<endl;
  }
}
};

int main(int argc, char const *argv[]) {
  int n,x;
  cin>>n;
  segTree obj(n);
  for(int i=1;i<=n;i++)
  {
    cin>>x;
    obj.increment(1,i,i,x);
  }
  obj.traverse(n);
  int k,l,r;
  cin>>k;
  for(int i=0;i<k;i++)
  {
    cin>>l>>r;
    if(i%2==0)
    {
      cout<<obj.mini(1,l,r)<<endl;
    }
    else cout<<obj.maxi(1,l,r)<<endl;
  }
  return 0;
}
