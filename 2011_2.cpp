#include<iostream>
#include<string>
#include<vector>

using namespace std;
vector<int> dp;

int main()
{
	string str;
	cin>>str;
	str=" "+str;
	int len=str.length()-1;
	dp.resize(len+1,0);
	dp[0]=1;
	for(int i=1;i<=len;i++)
	{
		int c=str[i]-'0';
		if(1<=c&&c<=9)
			dp[i]=dp[i-1]%1000000;
		if (i==1)
			continue;
		if(str[i-1]!=0)
		{
			int c1=str[i-1]-'0';
			c=c1*10+c;
			if(10<=c&&c<=26)
				dp[i]=(dp[i]+dp[i-2])%1000000;
		}
	}
	cout<<dp[len]<<endl;
}
