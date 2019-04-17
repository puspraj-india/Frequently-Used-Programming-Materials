#include<iostream>
#include<stdlib.h>
using namespace std;
int main(int count,char args[])
{	
	stringstream s("24");
	int x=0;
	s>>x;
	cout<<x;
	return 0;
}
