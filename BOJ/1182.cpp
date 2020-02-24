#include<iostream>
#include<vector>

using namespace std;
int n;
int s;
vector<int> num;
int cnt;
void dfs(int i,int sum)
{
   sum+=num[i];
   if(i>=n)
	   return ;
   if(sum==s)
	   cnt++;
   dfs(i+1,sum);
   dfs(i+1,sum-num[i]);
}
int main()
{
	cin>>n>>s;
	num.resize(n);
	for(int i=0;i<n;i++)
		cin>>num[i];
    dfs(0,0);
	cout<<cnt<<endl;
}
