#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<int>v;
vector<int>dp;

int main()
{
	int n;
	cin>>n;
	v.resize(n+1,0);
	dp.resize(n+1,0);
	for(int i=1;i<=n;i++)
		cin>>v[i];
	dp[1]=v[1];
	for(int i=2;i<=n;i++)
	{
		dp[i]=v[i];
		for(int j=1;j<i;j++)
		{
			dp[i]=max(dp[i],dp[i-j]+v[j]);
		}
	}
	cout<<dp[n]<<endl;
}
