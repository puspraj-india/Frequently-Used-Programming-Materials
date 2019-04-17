#include<iostream>
using namespace std;
int main()
{
    int T,i,j,n1,n2,n3,min,count;
    cin>>T;
    while(T--)
    {
        count=0;
        cin>>n1>>n2>>n3;
        min=(n1<=n2)?(n1<=n3?n1:n3):(n2<=n3?n2:n3);
        for (i=1;i<=min;i++)
        {
            if(n1%i==0 && n2%i==0 && n3%i==0)
            {
                count=count+1;
            }
        }
        cout<<count;
    }
    
}

