#include<iostream>
#include<queue>
int mat[51][51];
int N,M;
int arr[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
int copymat[51][51];
int ans=999999;
using namespace std;

bool check(int x,int y)
{
	if(x>=0&&x<N&&y>=0&&y<N)
		return true;
	else
		return false;
}
bool isfull()
{
   bool full=true;
   for(int i=0;i<N;i++)
	   for(int j=0;j<N;j++)
		   if(copymat[i][j]==0)
			   full=false;
   return full;
}
void matcopy()
{
  for(int i=0;i<N;i++)
	  for(int j=0;j<N;j++)
		  copymat[i][j]=mat[i][j];
}
int virus()
{
	queue<pair<int,int>> q;
	int time=0;
	matcopy();
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			if(copymat[i][j]==3)
				q.push({i,j});
	while(!q.empty())
	{
		int qsize=q.size();
		if(isfull())
			return time;
		for(int i=0;i<qsize;i++)
		{
	     	int x=q.front().first;
	    	int y=q.front().second;
	    	q.pop();
	    	for(int d=0;d<4;d++)
	    	{
		    	int new_x=x+arr[d][0];
		    	int new_y=y+arr[d][1];
		    	if(check(new_x,new_y))
		     	{
			    	if(copymat[new_x][new_y]==0||copymat[new_x][new_y]==2)
					{	
						copymat[new_x][new_y]=-1;
						q.push({new_x,new_y});
					}
		    	}
	    	}
    	}
		time++;
	}
	return time;
}
void dfs(int idx,int cnt)
{
	if(cnt==M)
	{
		int res;
		res=virus();
        if(isfull())
		{
			if(ans>res)
				ans=res;
		}
		return ;
	}
	for(int i=idx;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(mat[i][j]==2)
			{
				mat[i][j]=3;
				dfs(i,cnt+1);
				mat[i][j]=2;
			}
		}
	}

}
int main()
{
	cin>>N>>M;
	for(int n=0;n<N;n++)
	{	
		for(int m=0;m<N;m++)
		{
			cin>>mat[n][m];
		}
	}
    dfs(0,0);
	if(ans==999999)
		cout<<-1<<endl;
	else
	    cout<<ans<<endl;
}
