#include<iostream>
#include<vector>

using namespace std;
vector<int>dp;

int main ()
{
	string num;
	cin>>num;
	num=" "+num;
	int len=num.length()-1;
	dp.resize(len+1,0);
	dp[0]=1;
	for(int i=1;i<=len;i++)
	{
		int c=num[i]-'0';
		if(1<=c&&c<=9)
			dp[i]=(dp[i]+dp[i-1])%1000000;
		if(i==1)
			continue;
		if(num[i-1]==0)
			continue;
		c=stoi(num.substr(i-1,2));
		if(10<=c&&c<=26)
		{
			dp[i]=(dp[i-2]+dp[i])%1000000;
		}
	}
	cout<<dp[len];
}

