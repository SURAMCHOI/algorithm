#include<iostream>
#include<vector>


using namespace std;
vector<int>visited;
vector<vector<int> >adj;

void dfs(int n,int color)
{
	visited[n]=color;
	for(int i=0;i<adj[n].size();i++)
	{	
		int next=adj[n][i];
		if(!visited[next])
		{
			dfs(next,3-color);
		}
	}
}
bool bg(int n)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<adj[i].size();j++)
		{
			int num=adj[i][j];
			if(visited[i]==visited[num])
				return false;
		}
	}
	return true;
}
int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n,e;
		cin>>n>>e;
		visited.resize(n+1,0);
		adj.assign(n+1,vector<int>());
		adj.clear();
		int u,v;
		for(int i=0;i<e;i++)
		{
			cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		for(int i=1;i<=n;i++)
			if(!visited[i])
			  dfs(i,1);
		if(bg(n))
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
}
