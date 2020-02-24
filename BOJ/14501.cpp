#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int n;
vector<pair<int,int> >s;
int ans;
void dfs(int d,int total)
{
	if(d>=n+1)
	{
      ans=max(ans,total);
	  return;
	}
	if((d+s[d].first<=n+1))
	   dfs(d+s[d].first,total+s[d].second);
	if(d+1<=n+1)
       dfs(d+1,total);

}
int main()
{
  cin>>n;
  s.resize(n+1);
  for(int i=1;i<=n;i++)
  {
	  int t,p;
	  cin>>t>>p;
	  s[i].first=t;
	  s[i].second=p;
  }
  dfs(1,0);
  cout<<ans<<endl;
  
}
