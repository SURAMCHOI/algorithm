#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
int map[8][8];
int map2[8][8];
int n,m;
int arr[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int result=0;
int check(int x,int y)
{
  if(x>=0&&x<n&&y>=0&&y<m)
	  return true;
  return false;
}
void bfs()
{
	int aftervirus[8][8];
	queue<pair<int,int> >q;
	for(int i=0;i<n;i++)
	{	
		for(int j=0;j<m;j++)
		{	
			aftervirus[i][j]=map2[i][j];
			if(aftervirus[i][j]==2)
			{
				q.push(make_pair(i,j));
			}
		}
	}
	while(!q.empty())
	{
		int x=q.front().first;
		int y=q.front().second;
		for(int i=0;i<4;i++)
		{
			if(check(x+arr[i][0],y+arr[i][1]))
			{
				int new_x=x+arr[i][0];
				int new_y=y+arr[i][1];
				if(aftervirus[new_x][new_y]==0)
				{
					q.push(make_pair(new_x,new_y));
					aftervirus[new_x][new_y]=2;
				}
			}
		}
		q.pop();
	}
	int empty=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			if(aftervirus[i][j]==0)
				empty++;
		}
	result=max(empty,result);
}
void makewall(int num)
{
	if(num==3)
	{
		bfs();
		return ;
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(map2[i][j]==0)
			{
				map2[i][j]=1;
				makewall(num+1);
				map2[i][j]=0;
			}
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{	
		for(int j=0;j<m;j++)
		{
			cin>>map[i][j];
		}
	}
	for(int i=0;i<n;i++)
	{	
		for(int j=0;j<m;j++)
		{
			if(map[i][j]==0)
			{
				for(int k=0;k<n;k++)
					for(int h=0;h<m;h++)
						map2[k][h]=map[k][h];
				map2[i][j]=1;
				makewall(1);
				map2[i][j]=0;
			}
		}
	}
	cout<<result<<endl;
}
