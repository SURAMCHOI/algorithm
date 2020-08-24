#include<iostream>
#include<vector>
using namespace std;
int n;

bool isHan(int i)
{
  if(i<=99)
	  return true;
  vector<int> num;
  while(i>0)
  {
	num.push_back(i%10);
	i/=10;
  }
  int n=num[0]-num[1];
  for(int i=1;i<num.size()-1;i++)
  {
	  if(n!=(num[i]-num[i+1]))
		  return false;
  }
  return true;

}
int main()
{
  cin>>n;
  int cnt=0;
  for(int i=1;i<=n;i++)
  {
      if(isHan(i))
		  cnt+=1;
  }
  cout<<cnt<<endl;
}
