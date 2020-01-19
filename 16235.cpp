#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int N,M,K;
int a[11][11];
int g[11][11];
vector<int> v[11][11];
int ans=0;
int arr[8][2]={{-1,-1},{-1,0},{-1,+1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
bool check(int x,int y)
{
	if(x>=0&&x<N&&y>=0&&y<N)
		return true;
	else
		return false;
}
void tree_grow()
{
	for(int k=0;k<K;k++)
	{
		//봄& 여름
		for(int x=0;x<N;x++)
		{	
			for(int y=0;y<N;y++)
			{
				if(v[x][y].size())
				{	
					int dead=0;
					vector<int> temp;
					sort(v[x][y].begin(),v[x][y].end());
					for(int l=0;l<v[x][y].size();l++)
					{
						int age=v[x][y][l];
						if(g[x][y]>=age)
						{
							g[x][y]-=age;
							temp.push_back(age+1);
						}
						else
							dead+=age/2;
					}
				  v[x][y].clear();
				  for(int i=0;i<temp.size();i++)
					  v[x][y].push_back(temp[i]);
				  g[x][y]+=dead;
			}
		   }
		}
		//가을
		for(int x=0;x<N;x++)
	    {
			for(int y=0;y<N;y++)
			{
				if(v[x][y].size())
				{
					for(int i=0;i<v[x][y].size();i++)
					{
						int age=v[x][y][i];
						if(age%5==0)
						{
							for(int j=0;j<8;j++)
							{
								int new_x=x+arr[j][0];
								int new_y=y+arr[j][1];
								if(check(new_x,new_y))
								{
									v[new_x][new_y].push_back(1);

								}
							}

						}
					}
				}
			}
		}
		for(int x=0;x<N;x++)
		  for(int y=0;y<N;y++)
			g[x][y]+=a[x][y];
	}
}
int main()
{
  cin>>N>>M>>K;
  for(int i=0;i<N;i++)
  {
    for(int j=0;j<N;j++)
	{
		cin>>a[i][j];
		g[i][j]=5;
	}
  }
  int t1,t2,t3;
  for(int i=0;i<M;i++)
  {
	 cin>>t1>>t2>>t3;
	 v[t1-1][t2-1].push_back(t3);
  }
  tree_grow();
  for(int i=0;i<N;i++)
	  for(int j=0;j<N;j++)
		  ans+=v[i][j].size();
  cout<<ans<<endl;
}
