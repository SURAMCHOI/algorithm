#include<iostream>
#include<queue>
using namespace std;

char mat[1001][1001];
int visited[1001][1001];
int R,C;//r->x c->y
int arr[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int ans;
struct point
{
	int x;
	int y;
};
queue<point> jq;
queue<point> fq;
bool check(int x,int y)
{
	if(x>=0&&x<R&&y>=0&&y<C)
		return true;
	else
		return false;
}
bool bfs()
{
  while(1)
  {
	  //if(fq.empty()) return false;
	  int fsize=fq.size();
	  for(int iter=0;iter<fsize;iter++)
	  {
          int fx=fq.front().x;
	      int fy=fq.front().y;
		  fq.pop();
		  for(int i=0;i<4;i++)
		  {
			  int next_fx=fx+arr[i][0];
			  int next_fy=fy+arr[i][1];
			  if(check(next_fx,next_fy))
			  {
				  if(mat[next_fx][next_fy]!='#'&&mat[next_fx][next_fy]!='F')
				  {
					    fq.push({next_fx,next_fy});
					    mat[next_fx][next_fy]='F';
				  }
			  }
		  }
	  }
	  if(jq.empty()) return false;
      int jsize=jq.size();
	  for(int iter=0;iter<jsize;iter++)
	  {
		  int jx=jq.front().x;
		  int jy=jq.front().y;
		  if(jx==0||jx==R-1||jy==0||jy==C-1) return true;
		  jq.pop();
		  for(int i=0;i<4;i++)
		  {
			  int next_jx=jx+arr[i][0];
			  int next_jy=jy+arr[i][1];
			  if(check(next_jx,next_jy))
			  {
				  if(visited[next_jx][next_jy]==0&&mat[next_jx][next_jy]=='.')
					  {
						  jq.push({next_jx,next_jy});
						  visited[next_jx][next_jy]=1;
					  }
			   }
		  }
	  }
	  ans++;
  }
}
int main()
{
  cin>>R>>C;
  for(int i=0;i<R;i++)
  {	  
	  for(int j=0;j<C;j++)
	  {
		  cin>>mat[i][j];
		  if(mat[i][j]=='J')
		  {
			  jq.push({i,j});
			  mat[i][j]='.';
		  }
		  else if(mat[i][j]=='F')
		  {
			  fq.push({i,j});
			  visited[i][j]=0;

		  }
	  }
  }
  if(!bfs())
	  cout<<"IMPOSSIBLE"<<endl;
  else
	  cout<<ans+1<<endl;
}
