#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int n;
vector<pair<int,int>> mat[100001];
vector<int> visited;
int diameter=0;
int farestnode=0;

void dfs(int node,int dis)
{
  if(visited[node])
	  return ;
  visited[node]=true;
  if(diameter<dis)
  {
	  diameter=dis;
	  farestnode=node;
  }
  for(int i=0;i<mat[node].size();i++)
  {	  
          dfs(mat[node][i].first,dis+mat[node][i].second);
  }
}
int main()
{
 cin>>n;
 visited.resize(n+1,0);
 for(int i=0;i<n;i++)
 {
	 int node1;
	 cin>>node1;
	 while(1)
	 {
		 int node2,dis;
		 cin>>node2;
		 if(node2==-1)
		 {	 
			 break;
		 }
		 cin>>dis;
		 mat[node1].push_back(make_pair(node2,dis));
		 mat[node2].push_back(make_pair(node1,dis));
		
	 }
 }
 dfs(1,0);
 fill(visited.begin(),visited.end(),0);
 diameter=0;
 dfs(farestnode,0);
 cout<<diameter<<endl;
	
}

