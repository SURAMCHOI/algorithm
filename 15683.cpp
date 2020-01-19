#include<iostream>
#include<vector>

using namespace std;
int N,M;
int ans=999999;
int mat[9][9];
int arr[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
struct cctv
{
	int x;
	int y;
	int num;
	int r;
};
vector<cctv> c;
bool check(int x,int y)
{
	if(x>=0&&x<N&&y>=0&&y<M)
		return true;
	else
		return false;
}
int findspace()
{
	int cnt=0;
	for(int n=0;n<N;n++)
    {
		for(int m=0;m<M;m++)
		{
			if(mat[n][m]==0)
				cnt++;
		}
	}
	return cnt;
}
void update(int d,cctv c)
{
	d=d%4;
	int nx,ny;
	int x=c.x;
	int y=c.y;
	while(1)
	{
		nx=x+arr[d][0];
		ny=y+arr[d][1];
		if(check(nx,ny))
		{
			if(mat[nx][ny]==6)
			   break;
			if(mat[nx][ny]==0)
			   mat[nx][ny]=-1;
			x=nx;
			y=ny;
		}
		else
			break;
	}
}
/*void printmap()
{
	for(int n=0;n<N;n++)
	{
		for(int m=0;m<M;m++)
		{
			cout<<mat[n][m];
		}
		cout<<endl;
	}
	cout<<"-------------"<<endl;
}*/
void mapcopy(int res[9][9],int src[9][9])
{
	for(int n=0;n<N;n++)
		for(int m=0;m<M;m++)
			res[n][m]=src[n][m];
}
void dfs(int cnt)
{
   if(cnt==c.size())
   {
	   int res=findspace();
//	   printmap();
	   if(res<ans)
		   ans=res;
	   return ;
   }
   int backup[9][9];
   for(int d=0;d<c[cnt].r;d++)
   {
	   int type=c[cnt].num;
	   mapcopy(backup,mat);
	   if(type==1)
			   update(d,c[cnt]);
	   else if(type==2)
	   {
		  update(d,c[cnt]);
		  update(d+2,c[cnt]);
	   }
	   else if(type==3)
	   {		   
		   update(d,c[cnt]);
		   update(d+1,c[cnt]);
	   }
	   else if(type==4)
	   {
		   update(d,c[cnt]);
		   update(d+1,c[cnt]);
		   update(d+2,c[cnt]);
	   }
	   else if(type== 5)
	   {
		  update(d,c[cnt]);
		  update(d+1,c[cnt]);
		  update(d+2,c[cnt]);
		  update(d+3,c[cnt]);
	   }
	   dfs(cnt+1);
	   mapcopy(mat,backup);
   }
  
}
int main()
{
  cin>>N>>M;
  for(int n=0;n<N;n++)
  {	 
	  for(int m=0;m<M;m++)
	  {	  
		  cin>>mat[n][m];
		  if(1<=mat[n][m]&&mat[n][m]<=5)
		  {
			  int r=4;
			  if(mat[n][m]==2)
				  r=2;
			  else if(mat[n][m]==5)
				  r=1;
			  c.push_back({n,m,mat[n][m],r});
		  }
	  }
  }
  dfs(0);
  cout<<ans<<endl;
}
