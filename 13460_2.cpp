#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;
char mat[10][10];
int n,m;
int rx,ry,bx,by,hx,hy;
int ans=0;
int visited[10][10][10][10];
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
void move(int &x,int &y,int d)
{
	while(1)
	{
		x+=dir[d][0];
		y+=dir[d][1];
		if(mat[x][y]=='#')
		{
			x-=dir[d][0];
			y-=dir[d][1];
			return;
		}
		else if(mat[x][y]=='O')
			return;
	}
}
struct point
{
	int depth;
	int rx,ry,bx,by;
};
void bfs()
{
  queue<point> q;
  q.push({0,rx,ry,bx,by});
  visited[rx][ry][bx][by]=1;
  while(!q.empty())
  {
	  point cur=q.front();
	  q.pop();
	  if(cur.depth>10)
		  break;
	  if(mat[cur.rx][cur.ry]=='O')
	  {
		  ans=cur.depth;
		  return;
	  }
	  for(int i=0;i<4;i++)
	  {
		  rx=cur.rx;
		  ry=cur.ry;
		  bx=cur.bx;
		  by=cur.by;
		  move(rx,ry,i);
		  move(bx,by,i);
		  if(mat[bx][by]=='O')
			  continue;
		  if(rx==bx && ry==by)
		  {
			  switch(i)
			  {
				  case 0:
					cur.ry<cur.by?ry--:by--;
					 break;
				  case 1:
					 cur.ry<cur.by?by++:ry++;
					 break;
				  case 2:
					 cur.rx<cur.bx?rx--:bx--;
					 break;
				  case 3:
					 cur.rx<cur.bx?bx++:rx++;
					 break;
			  }
		  }
	      if(!visited[rx][ry][bx][by])
	     {
		    q.push({cur.depth+1,rx,ry,bx,by});
		    visited[rx][ry][bx][by]=1;
	     }
	  }
  }

}
int main()
{
  cin>>n>>m;
  for(int i=0;i<n;i++)
  {
	  cin>>mat[i];
	  for(int j=0;j<m;j++)
	  {
		  if(mat[i][j]=='R')
		  {
			  rx=i;
			  ry=j;
		  }
		  else if(mat[i][j]=='B')
		  {
			  bx=i;
			  by=j;

		  }
	  }
  }
   bfs();
   cout<<ans<<endl;
}
