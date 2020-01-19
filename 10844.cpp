#include<iostream>

using namespace std;
int v[101][10];
	  
int sum_dp(int n)
{
	int sum=0;
	for(int i=0;i<=9;i++)
		sum=(sum+v[n][i])%1000000000;
	return sum;
}
int main()
{
  int n;
  cin>>n;
  for(int i=1;i<=9;i++)
	  v[1][i]=1;
  for(int i=2;i<=n;i++)
	  for(int l=0;l<=9;l++)
	  {
		  if(l==0)
			  v[i][l]=v[i-1][1]%1000000000;
		  if(1<=l&&l<=8)
			  v[i][l]=(v[i-1][l-1]+v[i-1][l+1])%1000000000;
		  if(l==9)
			  v[i][l]=v[i-1][8]%1000000000;
      }
  cout<<sum_dp(n)%1000000000<<endl;
}
