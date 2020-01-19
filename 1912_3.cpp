#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> v;
vector<int> dp;
vector<int> sum;
int main()
{
	int n;
	cin>>n;
	v.resize(n,0);
	dp.resize(n,0);
	for(int i=0;i<n;i++)
		cin>>v[i];
	dp[0]=v[0];
	int ans=dp[0];
	for(int i=1;i<n;i++)
	{		
		dp[i]=max(dp[i-1]+v[i],v[i]);
		if(ans<dp[i])
			ans=dp[i];
		
	}
	cout<<ans<<endl;
}
