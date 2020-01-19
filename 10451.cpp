#include<iostream>
#include<vector>
#define MAX 1001
using namespace std;
vector<int>adj[MAX];
vector<int>visited;
int cycle;
void dfs(int n)
{
  visited[n]=true;
  for(int i=0;i<adj[n].size();i++)
  {
	  int next=adj[n][i];
	  if(!visited[next])
		  dfs(next);
	  else
		  cycle++;
  }
}
void findCycle(int n)
{
    cycle=0;
	for(int i=1;i<=n;i++)
	 if(!visited[i])
		 dfs(i);
}

int main()
{

	int t,n;
	cin>>t;
	for(int i=0;i<t;i++)
	{
       for(int j=1;j<MAX;j++)
		   adj[j].clear();
	   cin>>n;
	   visited.resize(n+1);
	   fill(visited.begin(),visited.end(),0);
	   for(int i=1;i<=n;i++)
	   {
		  int num;
		  cin>>num;
		  adj[i].push_back(num);
	   }
	   findCycle(n);
	   cout<<cycle<<endl;
	}
}
