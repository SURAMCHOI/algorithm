#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;
vector<int> v;
string str;
int main()
{
  cin>>str;
  v.resize(str.length(),0);
  int zero=0;
  int sum=0;
  for(int i=0;i<str.length();i++)
  {
      v[i]=(str[i]-'0');
      if((str[i]-'0')==0)
		  zero++;
	  sum+=str[i]-'0';
  }
  if(sum%3==0 && zero!=0)
  {
      sort(v.begin(),v.end());
	  reverse(v.begin(),v.end());
	  for(int i=0;i<v.size();i++)
	  {
		  cout<<v[i];
	  }
  }
  else
	  cout<<"-1"<<endl;
	 
}
