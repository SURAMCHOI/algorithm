#include<iostream>
#include<deque>
#include<vector>

using namespace std;
deque<int> q;
vector<int> v;
int n,m;
int bfs()
{
  int cnt=0;
  while(!q.empty())
  {
	 int res=0;
	 int curr=q.size();
	 int first=q.front();
	 for(int i=0;i<curr;i++)
	 {
	    if(first<q.at(i))
		{
			res=1;
		}
     }
	 if(res==1)
	 {
		 q.push_back(first);
	 }
	 else
	 {
		 if(first==v[m])
			return cnt+=1;
		 else
		 {	 
			 cnt+=1;
		 }
	 }
	 q.pop_front();
  }
  return cnt;
}
int main()
{
 int t;
 cin>>t;
 for(int i=0;i<t;i++)
 {
	cin>>n>>m;
	v.resize(n);
	for(int j=0;j<n;j++)
	{
		int tmp;
		cin>>tmp;
		q.push_back(tmp);
		v[i]=tmp;
	}
	int ans=bfs();
	cout<<ans<<endl;
	q.clear();
	v.clear();
 }

}
