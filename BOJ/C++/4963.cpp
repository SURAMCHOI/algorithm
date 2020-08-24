#include<iostream>
#include<vector>

using namespace std;
int w,h;
int mat[50][50];
int visited[50][50];
int cnt;
int arr[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

int check(int x,int y)
{
   if(x>=0&&y>=0&&x<h&&y<w)
	   return 1;
   else 
	   return 0;
}
void dfs(int x,int y)
{
	visited[x][y]=true;
	for(int i=0;i<8;i++)
	{
		if(check(x+arr[i][0],y+arr[i][1]))
		{
			int new_x=x+arr[i][0];
			int new_y=y+arr[i][1];
			if(!visited[new_x][new_y]&&mat[new_x][new_y]==1)
				dfs(new_x,new_y);
		}
	}
}
void dfsAll()
{
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			if(!visited[i][j]&&mat[i][j]==1)
			{	
				dfs(i,j);
				cnt++;
			}
		}
	}
}
int main()
{
	while(1)
	{
		cin>>w>>h;
		if(w==0&&h==0)
			return 0;
		for(int i=0;i<h;i++)
			for(int j=0;j<w;j++)
			{
				cin>>mat[i][j];
			}
         fill(visited[0],visited[0]+2500,0);
		 cnt=0;
		 dfsAll();
		 cout<<cnt<<endl;
	}
}
