#include<cstdio>
#include<algorithm>
#include<queue>
#include<utility>
//백준 7576번 토마토 
using namespace std;

int uldr[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int M,N;
int mat[1000][1000];
int visited[1000][1000];

int check(int x,int y)
{
	if(x<0||x>=N||y<0||y>=M) return 0;
	else return 1;
}
int complete()
{
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
	      if(mat[i][j]==0)
			  return -1;
	return 1;
}

int bfs()
{
	queue<pair<int,int> > q;
	for(int n=0;n<N;n++)
	{	
		for(int m=0;m<M;m++)
		{
           if(mat[n][m]==1)
			{
				q.push(make_pair(n,m));
				visited[n][m]=1;
			}
		}
	}
	int new_x,new_y;
	int component=0;
	while(!q.empty())
	{
	  int qSize=q.size();
	  for(int i=0;i<qSize;i++)
	  {
		  pair<int,int> n =q.front();
		  q.pop();
		  int x=n.first;
		  int y=n.second;
		  for(int j=0;j<4;j++)
		  {
			  new_x=x+uldr[j][0];
			  new_y=y+uldr[j][1];
			  if(check(new_x,new_y)&&(mat[new_x][new_y]==0)&&!visited[new_x][new_y])
			  {
				  visited[new_x][new_y]=1;
				  q.push(make_pair(new_x,new_y));
				  mat[new_x][new_y]=1;
			  }

		  }
	  }
	  ++component;
	}
 if(complete()==-1)
	 return -1;
 else 
	 return component-1;

}

int main()
{
  scanf("%d %d",&M,&N);
  for(int n=0;n<N;n++)
	  for(int m=0;m<M;m++)
		  scanf("%d",&mat[n][m]);
   printf("%d\n",bfs());

}

