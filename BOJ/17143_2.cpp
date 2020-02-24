#include<iostream>
#include<vector>

using namespace std;
int R,C,M;
struct shark
{
	int x;
	int y;
	int s;
	int d;
	int z;
};
vector<shark> mat[101][101];
int ans=0;
int arr[5][2]={{0,0},{-1,0},{1,0},{0,1},{0,-1}};
bool check(int x,int y)
{
	if(x>=0&&x<R&&y>=0&&y<C)
		return true;
	else
		return false;
}
void move(shark cur)
{
	for(int i=0;i<cur.size();i++)
	{
		int x=cur.x;
		int y=cur.y;
		int d=cur.d;
		for(int j=0;j<cur.z;j++)
		{
			int new_x=x+arr[d][0];
			int new_y=y+arr[d][1];
			if(check(new_x,new_y))
			{
			   x=new_x;
			   y=new_y;
			}
			else
			{
				if(d==1)
					d=2;
				else if(d==2)
					d=1;
				else if(d==3)
					d=4;
				else if(d==4)
					d=3;
			}
		}
		mat[cur.x][cur.y].clear();
		mat[x][y].push_back({x,y,s,d,z});
	}
}
void fishing()
{
	for(int i=0;i<C;i++)
	{
		int min=R-1;
		for(int j=0;j<R;j++)
		{
			if(mat[j][i].size()!=0)
			{
				if(min>j)
					j=min;


			}

		}
		ans+=mat[min][i].z;
		move();
		eat();
	}
}
int main()
{
	cin>>R>>C>>M;
	for(int m=0;m<M;m++)
	{
		int x,y,s,d,z;
		cin>>x>>y>>s>>d>>z;
		mat[x][y].push_back({x,y,s,d,z});
	}
	fishing();
	cout<<ans<<endl;
}
