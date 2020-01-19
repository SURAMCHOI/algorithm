#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> dp;
vector<int>v;
//백준 결과 틀렸다고 나오지만 왜 틀린지 알 수 없음
int main()
{
	int n;
	cin>>n;
	dp.resize(n+1,0);
	v.resize(n+1,0);
	for(int i=1;i<=n;i++)
		cin>>v[i];
	dp[n]=v[n];
	dp[n-1]=max(dp[n],dp[n]+v[n-1]);
	dp[n-2]=max(dp[n]+v[n-2],dp[n-1]);
	int ans=max(dp[n],max(dp[n-1],dp[n-2]));
	for(int i=n-3;i>=1;i--)
	{
		dp[i]=max(dp[i+2]+v[i],dp[i+3]+v[i+1]+v[i]);
		ans=max(ans,dp[i]);
	}
	cout<<ans<<endl;
	
	
}
