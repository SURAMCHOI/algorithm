#include<cstdio>
#include<cstring>
#include<algorithm>
//백준 2468번 안전영역
int mat[100][100];
int visited[100][100];
int uldr[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int N;

using namespace std;

int findMax()
{
	int ma=mat[0][0];
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			if(ma<mat[i][j]) ma=mat[i][j];
	return ma;
}
int check(int x,int y)
{
	if(x<0||x>=N||y<0||y>=N) return 0;
	return 1;
}
void dfs(int x,int y,int h)
{
   visited[x][y]=1;
   int new_x,new_y;
   for(int i=0;i<4;i++)
   {
      new_x=x+uldr[i][0];
	  new_y=y+uldr[i][1];
	  if(check(new_x,new_y)&&!visited[new_x][new_y]&&mat[new_x][new_y]>h)
		  dfs(new_x,new_y,h);
   }
}
int dfsMax(int h)
{
  int com=0;
  for(int i=0;i<N;i++)
  {	
	  for(int j=0;j<N;j++)
	  {	
		  if(mat[i][j]>h&&!visited[i][j])
		  {  
			  dfs(i,j,h);
			  com++;
		  }
	  }
  }	    
  return com;


}
int dfsAll()
{
  int maxx;
  int max_com=1;
  maxx=findMax();
  for(int i=0;i<maxx;i++)
  {
	  memset(visited,0,sizeof(visited));
	  max_com=max(dfsMax(i),max_com);
	  
  }
  return max_com;
}
int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			scanf("%d",&mat[i][j]);
	printf("%d\n",dfsAll());
}

