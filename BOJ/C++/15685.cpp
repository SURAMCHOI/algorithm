#include<iostream>
#include<vector>
#include<stack>

using namespace std;
struct dragon
{
	int x;
	int y;
	int d;
	int g;
};
int arr[4][2]={{1,0},{0,-1},{-1,0},{0,1}};
vector<dragon> ds;
int N;
int map[101][101];
int ans;
bool check(int x,int y)
{
	if(x>=0&&x<=100&&y>=0&&y<=100)
		return true;
	else 
		return false;
}
void make_dragon(dragon d)
{
  vector<int> v;
  int sx=d.x;
  int sy=d.y;
  int fx=sx+arr[d.d][0];
  int fy=sy+arr[d.d][1];
  v.push_back(d.d);
  map[sx][sy]=1;
  map[fx][fy]=1;
  for(int i=1;i<=d.g;i++)
  {
	  int vsize=v.size();
	  for(int j=vsize-1;j>=0;j--)
	  {
		  int nsx=fx;
		  int nsy=fy;
		  int d=v[j]+1;
		  d%=4;
		  int nfx=nsx+arr[d][0];
		  int nfy=nsy+arr[d][1];
          map[nfx][nfy]=1;
          v.push_back(d);
		  fx=nfx;
		  fy=nfy;

	  }
  }
}
void count()
{
	for(int x=0;x<=100;x++)
	{
		for(int y=0;y<=100;y++)
		{
			int dx=x+1;
			int dy=y;
			int rx=x;
			int ry=y+1;
			int dix=x+1;
			int diy=y+1;
			if(check(dx,dy)&&check(rx,ry)&&check(dix,diy))
			{
				if(map[x][y]!=0&&map[dx][dy]!=0&&map[rx][ry]!=0&&map[dix][diy]!=0)
					ans++;
			}
		}
	}

}
int main()
{
  cin>>N;
  for(int n=0;n<N;n++)
  {
	 int x,y,d,g;
	 cin>>x>>y>>d>>g;
	 ds.push_back({x,y,d,g});
  }
  for(int i=0;i<ds.size();i++)
  {
	  make_dragon(ds[i]);
  }
 count();
 cout<<ans<<endl;
}
