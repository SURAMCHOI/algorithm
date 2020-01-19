#include<iostream>
#include<vector>

using namespace std;
int r,c;
char mat[21][21];
int visited[28];
int ans;
int arr[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
bool check(int x,int y)
{
	if(x>=0&&x<r&&y>=0&&y<c)
		return true;
	else 
		return false;
}
void dfs(int x,int y,int cnt)
{
	visited[mat[x][y]-65]=1;
	for(int i=0;i<4;i++)
	{
		if(check(x+arr[i][0],y+arr[i][1]))
		{
			int new_x=x+arr[i][0];
			int new_y=y+arr[i][1];
            if(visited[mat[new_x][new_y]-'A']==1)
		       continue;
		    dfs(new_x,new_y,cnt+1);
			visited[mat[new_x][new_y]-'A']=0;
		}
	}
	ans=max(ans,cnt);
	
}
int main()
{
	cin>>r>>c;
	for(int i=0;i<r;i++)
		cin>>mat[i];
	dfs(0,0,1);
	cout<<ans<<endl;

}
