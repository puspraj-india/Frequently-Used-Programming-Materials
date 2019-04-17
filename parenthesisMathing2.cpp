#include<bits/stdc++.h>
using namespace std;
int main()
{
  string s;
  getline(cin,s);
  stack<char> l;
  int string_size=s.size();
  int flag=0;
  for(int i=0;i<string_size;i++)
  {
    if(s[i]=='('||s[i]=='['||s[i]=='{')
    {
      l.push(s[i]);
    }
    else if(s[i]==')'||s[i]=='}'||s[i]==']')
    {
      if(l.empty()==1)
      {
        flag=1;
        break;
      }
      if((l.top()==s[i])
      l.pop();
      else
      {
        flag=1;
        break;
      }
    }
  }
  if(flag==1||l.size()!=0) cout<<"Not matched\t";
  else cout<<"Matched";
  return 0;
}
