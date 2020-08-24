#include<iostream>
#include<vector>

using namespace std;
vector<int> v;

int dp(int n)
{
  if(n==1) return 1;
  if(n==2) return 2;
  if(v[n]!=-1) return v[n];
  v[n]=(dp(n-1)+dp(n-2))%10007;
  return v[n];
}

int main()
{
  int n;
  cin>>n;
  v.resize(n+1,-1);
  cout<<dp(n);
}
