#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
//백준 2178번 미로 탐색
using namespace std;

int mat[100][100];
int visited[100][100];
int uldr[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int N,M;

int check(int x,int y)
{
	if(x<0||x>=N||y<0||y>=M) return 0;
	return 1;
}

int bfs(int x,int y)
{
    memset(visited,0,sizeof(visited));
	queue< pair <int,int> > Q;
	visited[x][y]=1;
	Q.push(make_pair(x,y));
	int new_x,new_y;
	int level=0;
	int exit=0;
	while(!exit)
	{
		int qSize=Q.size();
		for(int i=0;i<qSize;i++)
		{
			pair<int,int> n=Q.front();
		    Q.pop();
		    x=n.first;
		    y=n.second;
			if(x==(N-1) && y==(M-1)) exit=1;
			for(int i=0;i<4;i++)
		    {
		      new_x=x+uldr[i][0];
		      new_y=y+uldr[i][1];
		      if(check(new_x,new_y)&&!visited[new_x][new_y]&&mat[new_x][new_y])
		      {
			     visited[new_x][new_y]=1;
			     Q.push(make_pair(new_x,new_y));	
		      }
		    }
	     }
		level++;
	}
return level;
}

int main()
{
	scanf("%d %d",&N,&M);
	for(int n=0;n<N;n++)
		for(int m=0;m<M;m++)
			scanf("%1d",&mat[n][m]);
	printf("%d\n",bfs(0,0));

}
