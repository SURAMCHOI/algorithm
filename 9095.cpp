#include<iostream>
#include<vector>

using namespace std;
vector<int> v;

int dp(int n)
{
	if(n==1) return 1;
	if(n==2) return 2;
	if(n==3) return 4;
	if(v[n]!=-1) return v[n];
	v[n]=dp(n-1)+dp(n-2)+dp(n-3);
	return v[n];
}

int main()
{
	int num;
	cin>>num;
	int n;
	for(int i=0;i<num;i++)
	{
		cin>>n;
		v.resize(n+1,-1);
		cout<<dp(n)<<endl;
	}
}
