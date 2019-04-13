#include<cstdio>
#include<algorithm>
#include<vector>
//백준 11047번 동전 0
using namespace std;

int N,K;
vector<int> coin;

int greedy(int sum)
{
	int min=0;
	int n=N-1;
	while(sum!=0)
	{
		if(sum<coin[n])
		{	
			n--;
			continue;
		}
		else
		{
			sum-=coin[n];
			min++;
		}
	    
	}
	return min;
}
int main ()
{
  scanf("%d %d",&N,&K);
  coin.resize(N);
  for(int n=0;n<N;n++)
   scanf("%d",&coin[n]);
  printf("%d\n",greedy(K));
}
