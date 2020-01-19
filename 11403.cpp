#include<iostream>
#include<queue>
#include<cstring>

using namespace std;
int mat[101][101];
int res[101][101];
int n;
int startnode;
int visited[101];
void bfs(int node)
{
   queue<int>q;
   q.push(node);
   while(!q.empty())
   {
	   node=q.front();
	   for(int i=1;i<=n;i++)
	   {
		   if(mat[node][i]==1&&!visited[i])
		   {
              res[startnode][i]=1;
			  visited[i]=true;
			  q.push(i);
		   }
	   }
	   q.pop();
   }
}
int main()
{
   cin>>n;
   for(int i=1;i<=n;i++)
	   for(int j=1;j<=n;j++)
		   cin>>mat[i][j];
   for(int i=1;i<=n;i++)
   {
       startnode=i;
	   memset(visited,0,sizeof(visited));
	   bfs(i);
   }
   for(int i=1;i<=n;i++)
   {
	   for(int j=1;j<=n;j++)
		   cout<<res[i][j]<<" ";
	 cout<<endl;
   }

}
