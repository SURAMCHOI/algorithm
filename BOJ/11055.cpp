#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
vector<int> dp;
vector<int> v;
int main()
{
	int n;
	cin>>n;
	v.resize(n+1,0);
	dp.resize(n+1,0);
	for(int i=1;i<=n;i++)
	{	
		cin>>v[i];
		dp[i]=v[i];
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<i;j++)
		{
			if(v[i]>v[j])
			{
				dp[i]=max(dp[i],dp[j]+v[i]);
			}
		}
	int ans=dp[1];
	for(int i=1;i<=n;i++)
		ans=max(ans,dp[i]);
	cout<<ans<<endl;
	
}
