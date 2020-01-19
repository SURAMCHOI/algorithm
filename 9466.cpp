#include<iostream>
#include<vector>

using namespace std;
vector<int> adj;
vector<int> visited;
vector<int> done;
int cnt;
void dfs(int n)
{
	visited[n]=true;
	int next=adj[n];
	if(!visited[next])
		dfs(next);
	else if(!done[next])
	{
		for(int i=next;i!=n;i=adj[i])
			cnt++;
		cnt++;
	}
	done[n]=true;
	
}
void dfsAll(int n)
{
	for(int i=1;i<=n;i++)
		if(!visited[i])
			dfs(i);
			
}
int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n;
		cin>>n;
		cnt=0;
		adj.resize(n+1);
		visited.resize(n+1);
		done.resize(n+1);
		fill(adj.begin(),adj.end(),0);
		fill(visited.begin(),visited.end(),0);
		fill(done.begin(),done.end(),0);
		for(int i=1;i<=n;i++)
			cin>>adj[i];
		dfsAll(n);
		cout<<n-cnt<<endl;
	}
}

