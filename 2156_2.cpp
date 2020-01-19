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
	dp[1]=v[1];
	dp[2]=max(v[1],v[1]+v[2]);
	int ans=dp[1];
	for(int i=3;i<=n;i++)
	{
		dp[i]=max(dp[i-1],max(dp[i-2]+v[i],dp[i-3]+v[i-1]+v[i]));
		ans=max(ans,dp[i]);
	}
    cout<<ans<<endl;
	  
    
}
