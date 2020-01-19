#include<iostream>
#include<vector>

using namespace std;
vector<int> visited;
vector<vector<int>>adj;
void dfs(int n);
int dfsAll(int n)
{
  int component=0;
  for(int i=1;i<=n;i++)
  {
	if(!visited[i])
	{
		dfs(i);
		component++;
	}
  }
  return component;

}
void dfs(int n)
{
   visited[n]=true;
   for(int i=0;i<adj[n].size();i++)
   {
	   int next=adj[n][i];
	   if(!visited[next])
	   {
		   dfs(next);
	   }
   }
}
int main()
{
	int n,m;
	cin>>n>>m;
	visited.resize(n+1,0);
	adj.assign(n+1,vector<int>());
	int u,v;
	for(int i=0;i<m;i++)
	{
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
   cout<< dfsAll(n)<<endl;
}
