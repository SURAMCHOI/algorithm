#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<pair<int,int>> tree[10001];
vector<int> visited;
int n;
int diameter=0;
int farest;
void dfs(int node,int cost)
{
    if(visited[node])
		return;
	visited[node]=true;
	if(diameter<cost)
	{
		diameter=cost;
		farest=node;
	}
	for(int i=0;i<tree[node].size();i++)
	{
		dfs(tree[node][i].first,cost+tree[node][i].second);
	}

}

int main()
{
  cin>>n;
  visited.resize(n+1,0); 
  int parent,child,cost;
  for(int i=0;i<n-1;i++)
  {
	  cin>>parent>>child>>cost;
	  tree[parent].push_back(make_pair(child,cost));
	  tree[child].push_back(make_pair(parent,cost));
  }
  dfs(1,0);
  diameter=0;
  fill(visited.begin(),visited.end(),0);
  dfs(farest,0);
  cout<<diameter<<endl;
}
