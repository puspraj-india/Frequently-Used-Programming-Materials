#include<iostream>
using namespace std;
class a_b_c
{
	int a,b,c;
	public:
	void disp(...)
{
	cout<<'h';
}
};

int main()
{
	a_b_c obj;
	obj.disp(1,2,3,4,5,6,7);
	return 0;
}

