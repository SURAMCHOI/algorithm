#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;
int n,m;
int mat[50][50];
int nmat[50][50];
int arr[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int ans;
vector<pair<int,int> > virus;
vector<int> index;
bool flag;
bool check(int x,int y)
{
	if(x>=0 && x<n &&y>=0 &&y<n)
		return true;
	else
		return false;
}
void bfs(int cnt)
{
    queue<pair<int,int> > q;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			mat[i][j]=nmat[i][j];
	for(int i=0;i<index.size();i++)
	{
		if(index[i]==1)
		{
			q.push(virus[i]);
			nmat[virus[i].first][virus[i].second]=3;

		}
	}
	int time=0;
	while(!q.empty())
	{
	  int qlen=q.size();
	  if(cnt==0)
	  {
           flag=true;
		   ans=min(ans,time);
		   return ;

	  }
	  time++;
	  for(int i=0;i<qlen;i++)
	  {
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		for(int j=0;j<4;j++)
		{
		   if(check(x+arr[j][0],y+arr[j][1]))
		   {
				int new_x=x+arr[j][0];
				int new_y=y+arr[j][1];
			    if(nmat[new_x][new_y]==0 || nmat[new_x][new_y]==2)
				{
					if(nmat[new_x][new_y]==0)
						cnt--;
					q.push(make_pair(new_x,new_y));
					nmat[new_x][new_y]=3;
				}
		   }
        }
	  }
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
	  for(int j=0;j<n;j++)
	  {
		  cin>>mat[i][j];
		  if(mat[i][j]==2)
		    virus.push_back(make_pair(i,j));
	  }
    }
  sort(virus.begin(),virus.end());
  ans=987654321;
  for(int i=0;i<m;i++)
	  index.push_back(1);
  for(int i=0;i<virus.size()-m;i++)
	  index.push_back(0);
  sort(index.begin(),index.end());
  int cnt=0;
  for(int i=0;i<n;i++)
	  for(int j=0;j<n;j++)
		  if(mat[i][j]==0)
			  cnt++;
  do 
  {
     bfs(cnt);
  }while(next_permutation(index.begin(),index.end()));
  if(!flag)
     cout<<-1<<endl;
  else
     cout<<ans<<endl;
}
