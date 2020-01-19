#include<iostream>
#include<queue>

using namespace std;
int n,m; //n이 가로, m이 세로 
int arr[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
int mat[1000][1000];
queue<pair<int,int> >q;

bool check(int x,int y)
{
   if(x>=0&&y>=0&&x<n&&y<m)
	   return true;
   else 
	   return false;
}
bool isallripen()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(mat[i][j]==0)
			{	
				
				return false;
			}
		}
	}
 return true;
}
int bfs()
{
  int day;
  
  while(!q.empty())
  {
    int cursize=q.size();
	for(int i=0;i<cursize;i++)
	{
	  int x=q.front().first;
	  int y=q.front().second;
      for(int j=0;j<4;j++)
	  {
		  if(check(x+arr[j][0],y+arr[j][1]))
		  {
			  int new_x=x+arr[j][0];
			  int new_y=y+arr[j][1];

			  if(mat[new_x][new_y]==0)
			  {
				  mat[new_x][new_y]=1;
				  q.push(make_pair(new_x,new_y));
			  }
		  }
	  }
	  q.pop();
	  if(q.empty()&&isallripen())
	 	  return day;
	  else if(q.empty()&&!isallripen())
		  return -1;
	}
	day++;
  }
}
int main()
{
	cin>>m>>n;
	int notomato=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{	
			cin>>mat[i][j];
			if(mat[i][j]==1)
				q.push(make_pair(i,j));
			else if(mat[i][j]==-1)
				notomato++;

		}
	if(q.size()==n*m-notomato)
		cout<<0<<endl;
	else
	{	
		cout<<bfs()<<endl;
}
