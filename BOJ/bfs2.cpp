#include<cstdio>
#include<cstring>
#include<queue>

//백준 5427번 불
using namespace std;

int T,W,H;
char mat[1000][1000];
int visited[1000][1000];
int udlr[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

int check_wall(int x,int y)
{
	if(x>0||x>=W||y<0||y>=H) return 0;
	else if(mat[x][y]=='.') return 1;
	return 0;
}
int check_exit(int x,int y)
{
   if(x==0||y==0||x==(W-1)||y==(H-1))
	 {
	      if(mat[x][y]=='.')
		      return 1;
	 }
   return 0;
}
int bfs()
{
	queue<pair<int> > Q_f;
	queue<pair<int> > Q_s;
    int s_x,s_y;
	int f_x,f_y;
	int exit=0;
	int second=0;
	for(int w=0;w<W;w++)
	{
		for(int h=0;h<H;h++)
	    {
           if(mat[w][h]=='*')
		   {
			   f_x=w;
			   f_y=h;
		   }
		   if(mat[w][h]=='@')
		   {
			   s_x=w;
			   s_y=h;
		   }

		}
	}
	Q_s.push(s_x,s_y);
	visited[s_x][s_y]=1;
	Q_f.push(f_x,f_y);
	visited[f_x,f_y]=1;
	while(!exit||!Q_s.empty())
	{
       int qSize=Q_s.size();
	   for(int i=0;i<qSize;i++)
	   {
         pair<int,int> f=Q_f.front();
		 Q_f.pop();
		 f_x=f.first();
		 f_y=f.second();
		 for(int i=0;i<4;i++) //for fire
		 {
            n_f_x=f_x+udlr[i][0];
			n_f_x=f_y+udlr[i][1];
			if(!check_wall(n_f_x,n_f_y)&&!visited[n_f_x][n_f_y])
			{
				Q_f.push(n_f_x,n_f_y);
				visited[n_f_x][n_f_y]=1;
			}
		 }
		 pair<int,int> s=Q_s.front();
		 Q_s.pop();
		 s_x=s.first();
		 s_y=s.second();
		 for(int i=0;i<4;i++)
		 {
           n_s_x=s_x+udlr[i][0];
		   n_s_y=s_y+udlr[i][1];
		   if(!check_wall(n_s_x,n_s_y)&&!visited[n_s_x][n_s_y])
		   {
			   if(check_exit(n_s_x,n_s_y))
				   exit=1;
			   else 
			   {
                   Q_s.push(n_s_x,n_s_y);
				   visited[n_s_x][n_f_y]=1;
			   }
		   }
		 }
       second++;
	   }

	}
	if (exit==0) return -1;
	return second;
}

int main()
{
	scanf("%d",&T);
	for(int t=0;t<T;t++)
	{
		scanf("%d %d",&W,&H);
		for(int w=0;w<W;w++)
			for(int h=0;h<H;h++)
				scanf("%c",&mat[w][h]);

		if(bfs()==-1)  printf("IMPOSSIBLE\n");
		else printf("%d\n",bfs()+1);
		memset(visited,0,sizeof(visited));
	}
}
