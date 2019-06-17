#include<iostream>
using namespace std;

int knapsack(int profit[],int weight[],int item,int wt)
{
	if(wt<=0||item<0)
	return 0;
	int a=0,b=0;
	if(weight[item]<=wt)
	{
		a=profit[item]+knapsack(profit,weight,item-1,wt-weight[item]);
	}
	b=knapsack(profit,weight,item-1,wt);
	
	
	return a>b?a:b;
}



int main()
{
	//Here everything is predefined and inputs are fixed
	int weight[]={2,7,3,4};
	int profit[]={5,20,20,10};
	int wt;
	cin>>wt;
	int p=knapsack(profit,weight,3,wt);
	cout<<p;
	return 0;
}
