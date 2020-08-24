#include<iostream>
#include<queue>

using namespace std;
int mat[1000][1000];
int n,m,notomato;
int arr[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
queue<pair<int,int> > q;
int check(int x,int y)
{
	if(x>=0&&y>=0&&x<n&&y<m)
		return 1;
	else 
		return 0;
}
bool isdone()
{
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			if(mat[i][j]==0)
				return false;
		}
	return true;
				
}
int bfs()
{
	int day=0;

	if(q.empty())
		return -1;
	while(!q.empty())
	{ 
		int currentSize=q.size();
		for(int i=0;i<currentSize;i++)
		{
		 int x=q.front().first;
		 int y=q.front().second;
		
		 for(int i=0;i<4;i++)
		 {
			 if(check(x+arr[i][0],y+arr[i][1]))
			 {
				 int new_x=x+arr[i][0];
				 int new_y=y+arr[i][1];
				 if(mat[new_x][new_y]==0)
				 {
					 mat[new_x][new_y]=1;
					 q.push(make_pair(new_x,new_y));
				 }
			 }
		 }
		 q.pop();
		 if(q.empty()&&isdone())
			 return day;
		 else if(q.empty()&&!isdone())
			 return -1;
		}
		day++;
	}
}
int main()
{
	cin>>m>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
		    cin>>mat[i][j];
			if(mat[i][j]==1)
				q.push(make_pair(i,j));
			else if (mat[i][j]==-1)
				notomato++;
		}
	if(q.size()==n*m-notomato)
		cout<<0<<endl;
	else
	{
		int result=bfs();
		cout<<result<<endl;
	
	}
}
