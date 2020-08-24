#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>

using namespace std;
vector<int> visited;
vector<vector<int>>adj;
void dfs(int n)
{ 
	cout<<n<<" ";
	visited[n]=true;
	for(int i=0;i<adj[n].size();i++)
	{	
		int next=adj[n][i];
		if(!visited[next])
		{
			visited[next]=true;
			dfs(next);
		}
	}
}
void bfs(int n)
{
  fill(visited.begin(),visited.end(),0);
  queue<int> q;
  q.push(n);
  visited[n]=true;
  while(!q.empty())
  {
	  int n=q.front();
	  q.pop();
	  cout<<n<<" ";
	  for(int i=0;i<adj[n].size();i++)
	  {
		  int next=adj[n][i];
		  if(!visited[next])
		  {
		      visited[next]=true; 
			  q.push(next);
		  }
	  }

  }
}
int main()
{
	int n,m,start;
	cin>>n>>m>>start;
	int u,v;
	visited.resize(n+1,0);
	adj.assign(n+1,vector<int>());
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
		sort(adj[i].begin(),adj[i].end());
	dfs(start);
  	cout<<endl;
	bfs(start);
}
