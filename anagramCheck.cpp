#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	char ch[40];
	char ch2[40];
	gets(ch);
	gets(ch2);
	char comp[256]={0};
	for(int i=0;ch[i]!='\0';i++)
	{
		comp[ch[i]]++;
	}
	for(int i=0;ch2[i]!='\0';i++)
	comp[ch2[i]]--;
	for(int i=0;i<256;i++)
	{
		if(comp[i]!=0)
		{
			cout<<"Not Anagram";
			return 0;
			
		}
	}
	cout<<"Anagram";
	return 0;
}
