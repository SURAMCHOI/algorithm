#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>

using namespace std;
int mat[100][100];
int n;
int visited[100][100];
int arr[4][2]={{0,1},{0,-1},{1,0},{-1,0}};

bool check(int x,int y)
{
	if(x>=0&&y>=0&&x<n&&y<n)
		return true;
	else
		return false;
}

void makelabel(int x,int y,int label)
{
   visited[x][y]=true;
   mat[x][y]=label;
   for(int i=0;i<4;i++)
   {
	   if(check(x+arr[i][0],y+arr[i][1]))
	   {
		   int new_x=x+arr[i][0];
		   int new_y=y+arr[i][1];
		   if(mat[new_x][new_y]==1&&!visited[new_x][new_y])
			   makelabel(new_x,new_y,label);
	   }
   }
}
int bfs(int label)
{
  int cnt=0;
  queue<pair<int,int> >q;
  for(int i=0;i<n;i++)
	  for(int j=0;j<n;j++)
		  if(mat[i][j]==label)
		  { 
			  q.push(make_pair(i,j));
			  visited[i][j]=true;
		  }
  while(!q.empty())
  {
	  int curr=q.size();
	  for(int i=0;i<curr;i++)
	  {
		  int x=q.front().first;
		  int y=q.front().second;
		  for(int i=0;i<4;i++)
		  {
			  if(check(x+arr[i][0],y+arr[i][1]))
			  {
				  int new_x=x+arr[i][0];
				  int new_y=y+arr[i][1];
				  if(!visited[new_x][new_y])
				  {
					  if(mat[new_x][new_y]==0)
					  {	  
						  q.push(make_pair(new_x,new_y));
						  visited[new_x][new_y]=true;
					  }
					  else if(mat[new_x][new_y] && mat[new_x][new_y]!=label)
						  return cnt;
				  }
			  }

		  }
		  q.pop();
	  }
	  cnt++;
  }
}

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>mat[i][j];
    int label=1;
	int ans=99999999;
	for(int i=0;i<n;i++)
	 for(int j=0;j<n;j++)
	   if(!visited[i][j]&&mat[i][j]==1)
	  	{   
			makelabel(i,j,label);
			label++;
		}
	for(int i=1;i<label;i++)	
	{
	   memset(visited,0,sizeof(visited));
	   ans=min(ans,bfs(i));
	}
	cout<<ans<<endl;

}
