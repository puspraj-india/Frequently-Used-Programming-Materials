#include<iostream>
using namespace std;
template<class T>
class trust
{
 T a;
 public:
 	trust(T x)
 	{
 		cout<<"I am not char";
	 }
};
template<>
class trust<char>
{

	public:
		trust(char x)
		{
			cout<<"I am  a character";
		}
};
int main ()
{
	trust <char>obj('4');// calls special trust function with special template
	return 0;
}
