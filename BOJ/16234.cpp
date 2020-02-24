#include<iostream>
#include<queue>
#include<vector>
#include<cmath>
#include<cstring>

using namespace std;
int mat[51][51];
int visited[51][51];
struct u
{
	int x;
	int y;
	int num;
};
vector<vector<u>> uv;
int N,L,R;
int ans;
int arr[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
void bfs(int x,int y);
bool check(int x, int y)
{
	if(x>=0&&x<N&&y>=0&&y<N)
		return true;
	else
		return false;
}
void move()
{
	while(1)
	{
	  for(int i=0;i<N;i++)
	   {
		 for(int j=0;j<N;j++)
		 { 
			if(visited[i][j]==0)
				bfs(i,j);
		 }
	   }
	   if(uv.size()==0)
		  return;
	   for(int i=0;i<uv.size();i++)
	   {
		   int sum=0;
		   for(int j=0;j<uv[i].size();j++)
		   {
               sum+=uv[i][j].num;
		   }
		   int np=sum/uv[i].size();
		   for(int j=0;j<uv[i].size();j++)
		   {
			   mat[uv[i][j].x][uv[i][j].y]=np;
		   }
	   }
	   //for(int i=0;i<N;i++)
	  // {
		//   for(int j=0;j<N;j++)
		//	   cout<<mat[i][j];
		//   cout<<endl;
	  // }
	   ans++;
	   memset(visited,0,sizeof(visited));
	   uv.clear();
	}
}
void bfs(int x,int y)
{
	queue<pair<int,int> >q;
	q.push({x,y});
	visited[x][y]=1;
	vector<u> tmp;
	tmp.push_back({x,y,mat[x][y]});
	while(!q.empty())
	{
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		for(int i=0;i<4;i++)
		{
			int new_x=x+arr[i][0];
			int new_y=y+arr[i][1];
			if(check(new_x,new_y))
		    {
				if(visited[new_x][new_y]==0)
				{
				  int cha=abs(mat[x][y]-mat[new_x][new_y]);
				  if(L<=cha && cha<=R)
				   {
                   tmp.push_back({new_x,new_y,mat[new_x][new_y]});
				   visited[new_x][new_y]=1;
				   q.push({new_x,new_y});
				  }
				}
			}
		}
	}
	if(tmp.size()>1)
		uv.push_back(tmp);
	else
		visited[x][y]=0;
}
int main()
{
  cin>>N>>L>>R;
  for(int i=0;i<N;i++)
	  for(int j=0;j<N;j++)
		  cin>>mat[i][j];
  move();
  cout<<ans<<endl;
}
