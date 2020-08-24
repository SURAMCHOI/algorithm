#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int visited[25][25];
int adj[25][25];
int arr[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
vector<int> v;
int cnt;
int n;
int check(int x,int y)
{
	if(x>=0&&y>=0&&x<n&&y<n)
		return 1;
	else 
		return 0;
}

void dfs(int x,int y)
{
   cnt++;
   visited[x][y]=true;
   for(int i=0;i<4;i++)
   {
	   if(check(x+arr[i][0],y+arr[i][1]))
	   {
		   int new_x=x+arr[i][0];
		   int new_y=y+arr[i][1];
		   if(!visited[new_x][new_y] && adj[new_x][new_y]==1)
			   dfs(new_x,new_y);
	   }
   }
}
void dfsAll()
{
   for(int i=0;i<n;i++)
   {	  
	   for(int j=0;j<n;j++)
	   {
          if(!visited[i][j]&&adj[i][j]==1)
		  {	  
			  dfs(i,j);
			  v.push_back(cnt);
			  cnt=0;
		  }
	   }
   }
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string str;
		cin>>str;
		for(int j=0;j<n;j++)
		{
			int c=str[j]-'0';
			adj[i][j]=c;
		}
	}
   dfsAll();
   cout<<v.size()<<endl;
   sort(v.begin(),v.end());
   for(int i=0;i<v.size();i++)
    cout<<v[i]<<endl;
	

}
