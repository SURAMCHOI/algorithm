#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> s;
vector<int> combi;
int k;
void dfs(int start,int depth)
{
	if(depth==6)
	{
		for(int i=0;i<6;i++)
			cout<<combi[i]<<' ';
		cout<<endl;
		return ;
	}
	for(int i=start;i<k;i++)
	{
		combi[depth]=s[i];
		dfs(i+1,depth+1);
	}
}
int main()
{
  while(1)
  {
    cin>>k;
	if(k==0)
		return 0;
	s.resize(k);
	combi.resize(6);
	for(int i=0;i<k;i++)
		cin>>s[i];
    dfs(0,0);
	cout<<endl;
	s.clear();
	combi.clear();
  }
}
