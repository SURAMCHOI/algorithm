#include<iostream>
#include<vector>
#define U 0
#define F 1
#define L 2
#define R 3
#define D 4
#define B 5
using namespace std;
int N,T;
struct box
{
	char color[3][3];
	int b[4];
	int d[4];
};
box cube[6];
void reset()
{
	for(int i=0;i<6;i++)
	{
		char c;
		int tmp[4];
		int tmp2[4];
		switch(i)
		{
			case 0:
				c='w';
				tmp={5,3,1,2};
				tmp2={2,1,0,3};
				break;
			case 1:
				c='r';
				tmp={0,3,4,2};
				tmp2={0,0,0,0};
				break;
			case 2:
				c='g';
				tmp={0,1,4,5};
				tmp2={3,0,1,1};
				break;
			case 3:
				c='b';
				tmp={0,5,4,1};
				tmp2={1,0,3,0};
				break;
			case 4:
				c='y';
				tmp={1,3,5,2};
				tmp2={0,1,2,3};
				break;
			case 5:
				c='o';
				tmp={0,2,4,3};
				tmp2={1,0,3,0};
				break;
		}
		for(int x=0;x<3;x++)
		{	
			for(int y=0;y<3;y++)
			{
				cube[i].color[x][y]=c;
			}
		}
		for(int j=0;j<4;j++)
			cube[i].b[j]=tmp[j];
	}

}
void rotate()
{
	reset();
	for(int i=0;i<v.size();i++)
	{
		string order=v[i];
		int index=order[1];
		if(order[2]=='+')//시계방향
		{
			int tmp[3];
			for(int j=0;j<4;j++)
			{
				for(int k=0;k<3;k++)
				{
					

				}
			}

		}
		else if(order[2]=='-')//반시계방향
		{
			for(int j=4;j>=0;j--)
			{

			}

		}

	}
}
int main()
{
  cin>>T;
  for(int t=0;t<T;t++)
  {
	  cin>>N;
	  vector<string> v;
	  v.resize(N);
	  for(int n=0;n<N;n++)
		  cin>>v;
	  rotate();
	  for(int i=0;i<3;i++)
	  {
		  for(int j=0;j<3;j++)
			  cout<<cube[0].color[i][j];
		  cout<<endl;
	  }
  }
}
