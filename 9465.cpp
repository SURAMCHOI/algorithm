#include<iostream>
#include<vector> 
#include<algorithm>
using namespace std;
vector<vector<int>> v;
vector<vector<int>> m;

int main()
{
	int num;
	int n;
	cin>>num;
	for(int i=0;i<num;i++)
	{
		cin>>n;
		v.assign(2,vector<int>(n+1,0));
		m.assign(2,vector<int>(n+1,0));
		for(int i=0;i<2;i++)
			for(int j=1;j<=n;j++)
				cin>>v[i][j];
		m[0][0]=m[1][0]=0;
		m[0][1]=v[0][1];
		m[1][1]=v[1][1];
		for(int i=2;i<=n;i++)
		{
			m[0][i]=max(m[1][i-1],m[1][i-2])+v[0][i];
			m[1][i]=max(m[0][i-1],m[0][i-2])+v[1][i];
		}
		cout<<max(m[0][n],m[1][n])<<endl;
		}
}

