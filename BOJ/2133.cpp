#include<iostream>
#include<vector>

using namespace std;
vector<int> dp;

int main()
{
	int n;
	cin>>n;
	dp.resize(n+1,0);
	dp[0]=1;
	dp[2]=3;
	for(int i=4;i<=n;i+=2)
	{
		dp[i]=dp[i-2]*3;
		 foar(int j=4;i-j>=0;j+=2)
		  dp[i]+=dp[i-j]*2;
	}
	cout<<dp[n]<<endl;
}
//규칙성 말고 고유의 모양을 찾는게 관건이였음 
