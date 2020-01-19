#include<iostream>
#include<queue>

using namespace std;
int mat[100][100];
int n,m;
int arr[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
queue<pair<int,int>>q;
int check(int x,int y)
{
	if(x>=0&&y>=0&&x<n&&y<m)
		return 1;
	else
		return 0;
}

int bfs()
{
  int cnt=1;
  q.push(make_pair(0,0));
  mat[0][0]=-1;
  int x,y;
  while(!q.empty())
  {
	  int curr=q.size();
	  for(int i=0;i<curr;i++)
	  {
		  x=q.front().first;
		  y=q.front().second;
		  for(int j=0;j<4;j++)
		  {
			  if(check(x+arr[j][0],y+arr[j][1]))
			  {
				  int new_x=x+arr[j][0];
				  int new_y=y+arr[j][1];
				  if(mat[new_x][new_y]==1)
				  {	  
					  if(new_x==n-1&&new_y==m-1)
						  return cnt+1;
					  q.push(make_pair(new_x,new_y));
					  mat[new_x][new_y]=-1;
				  }
			  }
		  }
		  q.pop();
	  }
	  cnt++;
  }
  return cnt;
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		string str;
		cin>>str;
		for(int j=0;j<m;j++)
		{
			int c=str[j]-'0';
			mat[i][j]=c;
		}
	}
	cout<<bfs()<<endl;
}
