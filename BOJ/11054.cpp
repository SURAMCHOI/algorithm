#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> v;
vector<int> dp_i;
vector<int> dp_d;
int main()
{
	int n;
	cin>>n;
	v.resize(n+1,0);
	dp_i.resize(n+1,1);
	dp_d.resize(n+1,1);
	for(int i=1;i<=n;i++)
		cin>>v[i];
	for(int i=1;i<=n;i++)
	{	
		for(int j=1;j<i;j++)
		{
			if(v[i]>v[j])
				dp_d[i]=max(dp_d[i],dp_d[j]+1);
		}
		dp_i[i]=dp_d[i];
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<i;j++)
		{
			if(v[i]<v[j])
				dp_i[i]=max(dp_i[i],dp_i[j]+1);
		}

	int ans=dp_i[1];
	for(int i=1;i<=n;i++)
		ans=max(ans,dp_i[i]);
	cout<<ans<<endl;

}
