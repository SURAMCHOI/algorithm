#include<cstdio>
#include<cstring>

using namespace std;

//백준 1012번 유기농 배추 


int mat[50][50];
int visited[50][50];
int udlr[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

int M,N,K;

int check(int x,int y)
{
	if(x<0||x>=M||y<0||y>=N) return 0;
	return 1;
}
void dfs(int x,int y)
{
  visited[x][y]=1;
  int new_x,new_y;
  for(int i=0;i<4;i++)
  {
	  new_x=x+udlr[i][0];
	  new_y=y+udlr[i][1];
	  if(check(new_x,new_y)==1&&mat[new_x][new_y]==1&&visited[new_x][new_y]!=1)
		  dfs(new_x,new_y);
  }
}
int dfsAll()
{
  int com=0;
  for(int m=0;m<M;m++)
	  for(int n=0;n<N;n++)
	  { 
		   if(mat[m][n]==1&&visited[m][n]!=1)
            {
				dfs(m,n);
				com++;
			}
	  }
  return com;
}

int main ()
{
  int T;
  int u,v;
  scanf("%d",&T);
  for(int t=0;t<T;t++)	
 { 
	 scanf("%d %d %d",&M,&N,&K);
	 for(int k=0;k<K;k++)
	 {
		 scanf("%d %d",&u,&v);
		 mat[u][v]=1;
	 }
	 printf("%d\n",dfsAll());
	 memset(mat,0,sizeof(mat));
	 memset(visited,0,sizeof(visited));
  
 }
}
