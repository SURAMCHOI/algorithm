#include<iostream>

using namespace std;
int v[1001][10];

int main()
{
	int n;
	cin>>n;
	int sum=0;
	for(int i=0;i<=9;i++)
		v[1][i]=1;
	for(int i=2;i<=n;i++)
		for(int j=0;j<=9;j++)
		   for(int k=j;k<=9;k++)
		     v[i][j]=(v[i][j]+v[i-1][k])%10007;
	for(int i=0;i<=9;i++)
		sum=(sum+v[n][i])%10007;
	cout<<sum%10007<<endl;
}
