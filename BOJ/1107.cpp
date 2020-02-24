#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;
int n;
vector<int> broken;
vector<int>::iterator it;
int canMove (int num)
{
	int length=0;
	if(num==0)
	{
		it=find(broken.begin(),broken.end(),0);
		if(it!=broken.end())
			return 0;
		else
		    return 1;
	}
    while(num>0)
	{
      it=find(broken.begin(),broken.end(),num%10);
	  if(it!=broken.end())
		  return 0;
	  else
	  {
	      length+=1;
	      num/=10;
	  }

	}
  return length;
}
int main()
{
  cin>>n;
  int m;
  cin>>m;
  for(int i=0;i<m;i++)
  {
    int t;
	cin>>t;
	broken.push_back(t);
  }
  int ans=abs(100-n); //(+,-번호만을 사용하는 경우 
  for(int i=0;i<=1000000;i++)  //숫자번호를 사용하는 경우(+,-사용) 
  {
	  int result=canMove(i);
	  if(result>0)
	  {
		  int more=abs(n-i);
		  ans=min(ans,result+more);
	  }
  }
  cout<<ans<<endl;
}
