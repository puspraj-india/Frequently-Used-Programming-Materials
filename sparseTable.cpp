#include<bits/stdc++.h>
using namespace std;
class SparseTable
{
  vector<int> *array;
  int r,c;
public:
  SparseTable(int n)
  {
    c=n;
    int x=log(n)/log(2);
    r=x;
    array = new vector<int>[x+1];
    for(int i=0;i<=x;i++)
    {
      array[i].resize(n);
    }
  }
  void createMatrix()
  {
    for(int i=0;i<c;i++)
    {
      cin>>array[0][i];
    }
    for(int i=1;i<=r;i++)
    {
      for(int j=0;j<c;j++)
      {
        int temp1=j+(1<<(i-1));
        if(temp1>=c)temp1=c-1;
        //if(i==1)cout<<temp1<<" ";
        array[i][j]=min(array[i-1][j],array[i-1][temp1]);
      }
    }
  }
  void display()
  {
    for(int i=0;i<=r;i++)
    {
      for(int j=0;j<c;j++)
      {
        cout<<array[i][j]<<" ";
      }
      cout<<endl;
    }
  }

  int query(int l,int r)
  {
    int total=r-l+1;
    int x=log(total)/log(2);
    int start,end;
    start=array[x][l];
    end=array[x][r-(1<<x)+1];
    return min(start,end);
  }
};



using namespace std;
int main()
{
  int n,x;
  cout<<"Enter the number of elements\t";
  cin>>n;
  SparseTable obj(n);
  obj.createMatrix();
  obj.display();
  int q,l,r;
  cin>>q;
  for(int i=0;i<q;i++)
  {
    cin>>l>>r;
    cout<<obj.query(l,r);
  }
}
