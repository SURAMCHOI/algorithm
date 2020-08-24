#include<iostream>

using namespace std;

long long v[91][2];

int main()
{
  int n;
  cin>>n;
  v[1][0]=0;
  v[1][1]=1;
  v[2][0]=1;
  for(int i=3;i<=n;i++)
  {
	  v[i][0]=v[i-1][1]+v[i-1][0];
	  v[i][1]=v[i-1][0];
  }
  cout<<v[n][0]+v[n][1]<<endl;

}
