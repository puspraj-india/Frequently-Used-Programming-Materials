#include<iostream>
using namespace std;
int main()
{
  int n;
  cin>>n;
  int space=n-1,temp2;
  int arr[n+1],brr[n+1];
  arr[0]=1,arr[0]=1;
  int temp;

  for(int i=0;i<n;i++)
  {
    for(int j=0;j<space;j++)
    {
      cout<<" ";
    }
    //cout<<1<<" ";
    temp=0;
    for(int k=0;k<i;k++)
    {
      if(i%2)
      {
        arr[k+1]=brr[k]+brr[k+1];
        cout<<arr[k]<<" ";
        temp=brr[k];
      }
      else
      {
        brr[k+1]=temp+arr[k];
        cout<<brr[k]<<" ";
        temp=arr[k];
      }
    }
    cout<<1;
    cout<<endl;
    space--;
  }
  return 0;
}
