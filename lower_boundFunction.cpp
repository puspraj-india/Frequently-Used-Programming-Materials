#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  int arr[200]={0};
  arr[199]=1;
  int carry=0,temp=0;
  int l=199;
  for(int i=2;i<=n;i++)
  {
    carry=0;
    for(int j=199;j>=l;j--)
    {
      temp=(i*arr[j]+carry);
      arr[j]=temp%10;
      carry=temp/10;
    }
    while(carry!=0)
    {
      arr[--l]=carry%10;
      carry/=10;
    }
  }
  for(int i=l;i<200;i++)
  {
    cout<<arr[i];
  }
  return 0;
}
