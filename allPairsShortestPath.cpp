#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int **a = new int*[n];
    for(int i=0;i<n;i++)
        a[i]= new int[n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {if(a[i][j]==-1) a[i][j]=INT_MAX;
            cout<<a[i][j]<<"\t";
        }
        cout<<endl;
    }


    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            if(i==k) continue;
            for(int j=0;j<n;j++)
            {
                if(j==k || i==j) continue;

                if(!( a[i][k]==INT_MAX||a[k][j]==INT_MAX))
                {
                    a[i][j]= a[i][j]<(a[i][k]+a[k][j])?a[i][j]:(a[i][k]+a[k][j]);
                }
            }
        }
    }


for(int i=0;i<n;i++)
{
    for(int j=0;j<n;j++)
    cout<<a[i][j]<<"\t";
    cout<<endl;
}
    return 0;
}
