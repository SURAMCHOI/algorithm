#include<iostream>
#include<vector>
#include<math.h>
#include<string>
using namespace std;
vector<int> v;
int find(int n)
{
	for(int i=0;i<v.size();i++)
		if(v[i]==n)
			return i;
	return -1;
}
int func(int p)
{
  for(int i=0;i<v.size();i++)
  {
   int curr=v[i];
   string tmp=to_string(curr);
   int len=tmp.length();
   int c=0;
   for(int i=0;i<len;i++)
   {
	  c+=pow(tmp[i]-'0',p);
   }
   int res=find(c);
   if(res==-1)
	  v.push_back(c);
   else
	  return res;
  }
}
int main()
{
   int a,p;
   cin>>a>>p;
   v.push_back(a);
   cout<<func(p)<<endl;
}
