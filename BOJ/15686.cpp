#include<iostream>
#include<cmath>
#include<vector>

using namespace std;
int N,M;
int map[51][51];
int ans=999999;
struct house
{
	int x;
	int y;
	int dis;
};
vector<house> v;
vector<pair<int,int>> ch;
vector<int> in;
void clean(vector<int> v);
void distance()
{
   for(int i=0;i<v.size();i++)
	   v[i].dis=999999;
   for(int i=0;i<in.size();i++)
   {
	   if(in[i]==1)
	   {
		   for(int j=0;j<v.size();j++)
		   {
			   int tmp=abs(ch[i].first-v[j].x)+abs(ch[i].second-v[j].y);
			   if(tmp<v[j].dis)
				   v[j].dis=tmp;
		   }
	   }
   }
	
}
void dfs(int idx,int cnt)
{
	if(cnt==M)
	{	
		distance();
		int sum=0;
		for(int i=0;i<v.size();i++)
		{	
			sum+=v[i].dis;
		}
		if(ans>sum)
			ans=sum;
		return ;
	}
	vector<int> tmp;
	tmp.resize(ch.size(),0);
	for(int i=idx;i<ch.size();i++)
	{
		in[i]=1;
		dfs(i+1,cnt+1);
		in[i]=0;
	
	}
	
}
void clean(vector<int> v)
{
	for(int i=0;i<v.size();i++)
		v[i]=0;
}
int main()
{
  cin>>N>>M;
  for(int i=0;i<N;i++)
  {	  
	  for(int j=0;j<N;j++)
	  {	  
		  cin>>map[i][j];
		  if(map[i][j]==1)
			  v.push_back({i,j,999999});
		  else if(map[i][j]==2)
			  ch.push_back(make_pair(i,j));
	  }
  }
  in.resize(ch.size(),0);
  dfs(0,0);
  cout<<ans<<endl;
}
