#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;
vector<int> dp;
int doub(int n)
{
	return n*n;
}

int main()
{
	int n;
	cin>>n;
	dp.resize(n+1,0);
	for(int i=1;i<=n;i++)
	{
		dp[i]=i;
		for(int j=1;j*j<=i;j++)
			dp[i]=min(dp[i],dp[i-j*j]+1);
	}
	cout<<dp[n]<<endl;
	
}
