#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int v;
vector<pair<int,int> > tree[100001];
vector<int> visited;
int farest;
int diameter;
void dfs(int node,int cost)
{
  if(visited[node])
	  return ;
  visited[node]=true;
  if(cost>diameter)
  {
	  diameter=cost;
	  farest=node;
  }
  for(int i=0;i<tree[node].size();i++)
  {
      int next=tree[node][i].first;
	  if(!visited[next])
      {
	    dfs(next,cost+tree[node][i].second);
      }
  }
	  
}
int main()
{
	cin>>v;
	int node;
	visited.resize(v+1,0);
	for(int i=0;i<v;i++)
	{
      cin>>node;
	  while(1)
	  {
		int t1,t2;
		cin>>t1;
		if(t1==-1)
		{   
			break;
		}
		cin>>t2;
		tree[node].push_back(make_pair(t1,t2));
		tree[t1].push_back(make_pair(node,t2));
	  }
	}
	dfs(1,0);
	fill(visited.begin(),visited.end(),0);
	diameter=0;
	dfs(farest,0);
	cout<<diameter<<endl;



}
