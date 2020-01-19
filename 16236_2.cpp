#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
#include<functional>

using namespace std;
int n;
int mat[21][21];
int visited[21][21];
int dist[21][21];
int arr[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
int ans=0;
struct Fish
{
	int cnt=0,dist=0;
	int x;
	int y;
	int size;
	Fish(int x,int y,int dist,int size)
	{
		this->x=x;
		this->y=y;
		this->dist=dist;
		this->size=size;
	}
	Fish(){};
};
Fish shark;
struct cmp{
 bool operator() (const Fish &f1,const Fish &f2)
 {
	if(f1.dist>f2.dist)
		return true;
	else if(f1.dist==f2.dist && f1.x>f2.x)
		return true;
	else if(f1.dist==f2.dist && f1.x==f2.x && f1.y>f2.y)
		return true;
	return false;
 }
};
bool check(int x,int y)
{
	if(x>=0&&x<n&&y>=0&&y<n)
		return true;
	else 
		return false;
}
bool eat()
{
  queue<pair<int,int> > q;
  q.push({shark.x,shark.y});
  visited[shark.x][shark.y]=1;
  priority_queue<Fish,vector<Fish>,cmp> pq;
  while(!q.empty())
  {
    int x=q.front().first;
	int y=q.front().second;
	q.pop();
    for(int j=0;j<4;j++)
	{
	    int new_x=x+arr[j][0];
		int new_y=y+arr[j][1];
		if(check(new_x,new_y))
		{
		   if(visited[new_x][new_y]==0)
		   {
			   if(mat[new_x][new_y]<=shark.size)
			   {
				   visited[new_x][new_y]=1;
				   dist[new_x][new_y]=dist[x][y]+1;
				   q.push({new_x,new_y});
				   if(1<=mat[new_x][new_y]&&mat[new_x][new_y]<shark.size)
					   pq.push(Fish(new_x,new_y,dist[new_x][new_y],mat[new_x][new_y]));
			   }
			}
		}
	}
  }
  if(!pq.empty())
  {
	 Fish food=pq.top();
	 mat[shark.x][shark.y]=0;
     shark.x=food.x;
	 shark.y=food.y;
	 shark.dist+=food.dist;
	 shark.cnt++;
	 if(shark.cnt==shark.size)
	 {
		 shark.size++;
		 shark.cnt=0;
	 }
	 memset(dist,0,sizeof(dist));
	 memset(visited,0,sizeof(visited));
	 return true;
  } 
  return false;
}
int main ()
{
  cin>>n;
  for(int i=0;i<n;i++)
  {
	  for(int j=0;j<n;j++)
	  {
		  cin>>mat[i][j];
		  if(mat[i][j]==9)
		  {
			  shark.x=i;
			  shark.y=j;
			  shark.size=2;
			  mat[i][j]==0;
		  }
	  }
  }
  while(eat());
  cout<<shark.dist<<endl;
}
