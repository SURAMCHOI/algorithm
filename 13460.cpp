#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;
int n,m,ans=-1;
char mat[12][12];
int rx,ry;
int bx,by;
int hx,hy;
int arr[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int visited[12][12][12][12];
struct point
{
	int depth;
	int rx,ry,bx,by;
};
void move(int& x,int& y,int d)
{
	while(1)
	{
       x+=arr[d][0];
	   y+=arr[d][1];
	   if(mat[x][y]=='#')
	   {
		   x-=arr[d][0];
		   y-=arr[d][1];
		   break;
	   }
	   else if(mat[x][y]=='O')
		   break;
	}
}
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
		if(cur.rx==hx && cur.ry==hy) 
		{
			ans=cur.depth;
			break;
		}
		for(int i=0;i<4;i++)
		{
            rx=cur.rx;
			ry=cur.ry;
			bx=cur.bx;
			by=cur.by;
			move(rx,ry,i);
			move(bx,by,i);
			if(bx==hx && by==hy)
				continue;
			if(rx==bx && ry==by)
			{
		       switch(i)
			   {
				   case 0:
					   cur.ry<cur.by? ry--:by--; break;
				   case 1:
					   cur.ry<cur.by? by++:ry++; break;
				   case 2:
					   cur.rx<cur.bx? rx--:bx--;break;
				   case 3:
					   cur.rx<cur.bx? bx++:rx++;break;
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
		  else if(mat[i][j]=='O')
		  {
              hx=i;
			  hy=j;
		  }
	  }
  }
  bfs();
  cout<<ans<<endl;

}
