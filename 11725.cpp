#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<vector<int> > tmp;
vector<int> visited;
vector<int> parent;
int n;
void bfs()
{
  queue<int> q;
  q.push(1);
  visited[1]=true;
  while(!q.empty())
  {
	  int curr=q.front();
      for(int i=0;i<tmp[curr].size();i++)
      {
		  if(!visited[tmp[curr][i]])
	      {
		      parent[tmp[curr][i]]=curr;
		      q.push(tmp[curr][i]);
			  visited[tmp[curr][i]]=true;
	      }
      }
	  q.pop();
  }
}
int main()
{
	cin>>n;
	int t1,t2;
	tmp.assign(n+1,vector<int>());
	visited.resize(n+1,0);
	parent.resize(n+1,0);
	for(int i=1;i<n;i++)
	{
      cin>>t1>>t2;
	  tmp[t1].push_back(t2);
	  tmp[t2].push_back(t1);
	}
	bfs();
	for(int i=2;i<=n;i++)
		cout<<parent[i]<<"\n";
}
