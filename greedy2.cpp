#include<cstdio>
#include<vector>
#include<algorithm>
//백준 1931 번 회의실배정 

using namespace std;

int main ()
{
  int N;
  int min=0;
  int count=0;
  vector<pair<int,int> > v;
  scanf("%d",&N);
  int a,b;
  for(int n=0;n<N;n++)
  {
	scanf("%d %d",&a,&b);
	v.push_back(pair<int, int> (b,a));
  }
  sort(v.begin(),v.end());
  for(int i=0;i<N;i++)
  {
	  if(v[i].second>=min)
	  {
		  count++;
		  min=v[i].first;
	  }
  }

  printf("%d\n",count);
}
