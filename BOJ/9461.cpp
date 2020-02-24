#include<iostream>
#include<vector>

using namespace std;
vector<long long>dp;

int main()
{
	int tn;
	cin>>tn;
	int n;
	for(int i=1;i<=tn;i++)
	{
		cin>>n;
		dp.resize(n+1,0);
		dp[1]=dp[2]=dp[3]=1;
		dp[4]=2;
		for(int i=5;i<=n;i++)
			dp[i]=dp[i-5]+dp[i-1];
		cout<<dp[n]<<endl;
	}
}
