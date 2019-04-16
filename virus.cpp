#include<cstdio>
#include<algorithm>
#include<vector>
//백준 2606번 바이러스 
//-질문게시판 참조해서 여러가지 예제 입력
using namespace std;

int N,M;
vector<bool> visited;
vector<vector<int> > adj;
int component;
void dfs(int curr)
{
  visited[curr]=true;
  for(int i=0;i<adj[curr].size();i++)
  { 
	  if(!visited[adj[curr][i]])
	  {
		   component++;
		   dfs(adj[curr][i]);
	  }
  }
}


int main()
{
 scanf("%d",&N);
 scanf("%d",&M);
 int index,num;
 adj.resize(N+1);
 visited.resize(N+1,0);
 for(int i=0;i<M;i++)
 {
	 scanf("%d %d",&index,&num);
	 adj[index].push_back(num);
	 adj[num].push_back(index);
 }
 dfs(1);
 printf("%d\n",component);

}
