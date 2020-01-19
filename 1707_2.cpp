#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<vector<int> > graph;
vector<int> color;
int v,e;

void dfs(int node,int c)
{
   color[node]=c;
   for(int i=0;i<graph[node].size();i++)
   {
	   int next=graph[node][i];
	   if(color[next]==0)
	   {
		   dfs(next,3-c);
	   }
   }
   
}
bool isbg()
{
	for(int i=1;i<=v;i++)
	{
		for(int j=0;j<graph[i].size();j++)
		{
			int node=graph[i][j];
			if(color[i]==color[node])
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
        cin>>v>>e;
		graph.resize(v+1);
		color.resize(v+1);
		for(int i=0;i<e;i++)
		{
			int t1,t2;
			cin>>t1>>t2;
			graph[t1].push_back(t2);
			graph[t2].push_back(t1);
		}
        for(int i=1;i<=v;i++)
		{
			if(color[i]==0)
				dfs(i,1);
		}
	    if(isbg())
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
		graph.clear();
		color.clear();
	}

}









