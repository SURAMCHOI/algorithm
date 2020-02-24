#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<vector<int> > v;
vector<vector<int> > dp;

int main()
{
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int n;
		cin>>n;
		v.assign(2,vector<int>(n+1,0));
		dp.assign(2,vector<int>(n+1,0));
		for(int i=0;i<2;i++)
			for(int j=1;j<=n;j++)
				cin>>v[i][j];
		dp[0][1]=v[0][1];
		dp[1][1]=v[1][1];
		for(int i=2;i<=n;i++)
		{
			dp[0][i]=max(dp[1][i-1]+v[0][i],dp[1][i-2]+v[0][i]);
			dp[1][i]=max(dp[0][i-1]+v[1][i],dp[0][i-2]+v[1][i]);
		}
		cout<<max(dp[0][n],dp[1][n])<<endl;
	}
}

