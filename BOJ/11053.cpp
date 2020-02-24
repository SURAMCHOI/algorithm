#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<int> a;
vector<int> m;

int main()
{
	int n;
	cin>>n;
	a.resize(n+1,0);
	m.resize(n+1,1);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	 for(int j=1;j<i;j++)
	 {
		 if(a[i]>a[j])
		 {
			 m[i]=max(m[i],m[j]+1);
		 }
	 }
	int ans=m[1];
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,m[i]);
	}
	
	cout<<ans<<endl;

}
