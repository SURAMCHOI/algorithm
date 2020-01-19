#include<iostream>

using namespace std;
int N,H,M;
int laddercnt;
int ladder[31][11];
bool flag=false;
void dfs(int idx,int cnt)
{
	if(flag)
		return ;
	if(cnt==laddercnt)
	{
		bool possible=true;
		for(int i=1;i<=N;i++)
		{
			int row=i;
			for(int h=0;h<H;h++)
			{
				if(ladder[h][row]==1)
				  row++;
				else if(row>1&&ladder[h][row-1]==1)
				  row--;
			}
           if(row!=i)
		   {
			   possible=false;
			   break;
		   }
		}
		if(possible)
			flag=true;
		return ;
	}
	for(int i=idx;i<H;i++)
	{
		for(int j=1;j<N;j++)
		{
			if(!ladder[i][j-1]&&!ladder[i][j]&&!ladder[i][j+1])
			{
				ladder[i][j]=1;
				dfs(i,cnt+1);
				ladder[i][j]=0;
			}
		}
	}
}
int main()
{
  cin>>N>>M>>H;
  for(int m=0;m<M;m++)
  {
	  int h,n;
	  cin>>h>>n;
	  ladder[h-1][n]=1;
  }
  for(int i=0;i<=3;i++)
  {
	  laddercnt=i;
	  dfs(0,0);
	  if(flag)
	  {
		  cout<<laddercnt<<endl;
		  return 0;
	  }
  }
  cout<<-1<<endl;
}
