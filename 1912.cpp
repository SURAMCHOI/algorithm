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
	int ans=dp[1];
	for(int i=2;i<=n;i++)
	{
		dp[i]=max(dp[i-1]+v[i],v[i]);
		if(ans<dp[i])
			ans=dp[i];
	}
	for(int i=1;i<=n;i++)
		cout<<dp[i]<<endl;
	cout<<ans<<endl;

}
