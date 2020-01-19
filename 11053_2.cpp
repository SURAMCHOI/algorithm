#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<int> v;
vector<int> dp;
int main()
{
  int n;
  cin>>n;
  v.resize(n+1,0);
  dp.resize(n+1,0);
  for(int i=1;i<=n;i++)
	  cin>>v[i];
  int ans=dp[1];
  for(int i=1;i<=n;i++)
  {
	  for(int j=1;j<i;j++)
	  {
		  if(v[i]>v[j])
			  dp[i]=max(dp[j]+1,dp[i]+1);
	  }
  }
  cout<<dp[n]<<endl;
}
