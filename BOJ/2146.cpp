#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>

using namespace std;
int mat[100][100];
int visited[100][100];
int arr[4][2]={{0,1},{0,-1},{1,0},{-1,0}};

int n;
int check(int x,int y)
{
	if(x>=0&&y>=0&&x<n&&y<n)
		return 1;
	else 
		return 0;
}
int dfs(int x,int y, int cnt)
{
    visited[x][y]=true;
	mat[x][y]=cnt;
	for(int i=0;i<4;i++)
	{
		if(check(x+arr[i][0],y+arr[i][1]))
		{
			int new_x=x+arr[i][0];
			int new_y=y+arr[i][1];
			if(!visited[new_x][new_y]&&mat[new_x][new_y])
			{
				dfs(new_x,new_y,cnt);
			}
		}
	}
}
int bfs(int cnt)
{
	queue<pair<int,int> > q;
	int result=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(mat[i][j]==cnt)
			{	
				visited[i][j]=true;
				q.push(make_pair(i,j));
			}
	while(!q.empty())
	{
	 int curr=q.size();
	 for(int i=0;i<curr;i++)
	 {
		 int x=q.front().first;
		 int y=q.front().second;
		 q.pop();
		 for(int i=0;i<4;i++)
		 {
			 if(check(x+arr[i][0],y+arr[i][1]))
			 {
				 int new_x=x+arr[i][0];
				 int new_y=y+arr[i][1];
				 if(mat[new_x][new_y]&&mat[new_x][new_y]!=cnt)
				 {
					 return result;
				 }
				 else if (mat[new_x][new_y]==0&&!visited[new_x][new_y])
				 {
                     visited[new_x][new_y]=true;
					 q.push(make_pair(new_x,new_y));
				 }
			 }
		 }
	 }
	 result++;
	}

}
int main()
{ 
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			cin>>mat[i][j];
		}
	int cnt=1;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{	
			if(!visited[i][j]&&mat[i][j])
			{
				dfs(i,j,cnt++);
			}
		}
	int result=999999999;

	for(int i=1;i<cnt;i++)
	{
		memset(visited,0,sizeof(visited));
		result=min(result,bfs(i));
	}
	cout<<result<<endl;
}
