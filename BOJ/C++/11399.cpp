#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> v;
int main()
{
	int n;
	cin>>n;
	v.resize(n,0);
	for(int i=0;i<n;i++)
		cin>>v[i];
	sort(v.begin(),v.end());
	v[1]+=v[0];
	for(int i=2;i<n;i++)
	{
	     v[i]+=v[i-1];
	}
	int sum=0;
	for(int i=0;i<n;i++)
	{
		sum+=v[i];
	}
	cout<<sum<<endl;
}
