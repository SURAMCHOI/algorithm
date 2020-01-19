#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<pair<int,int> > v;
int cnt=1;
int main()
{
   int n;
   cin>>n;
    // pair.first = 끝나는 시간, pair.second = 시작하는 시간 
   int t1,t2;
   for(int i=0;i<n;i++)
   {
      cin>>t1>>t2;
	  v.push_back(make_pair(t2,t1));
   }
   sort(v.begin(),v.end());
   int finish=v[0].first;
   for(int i=1;i<n;i++)
   {
	   if(finish<=v[i].second)
	   {
		   cnt++;
		   finish=v[i].first;
	   }
   }
   cout<<cnt<<endl;
   
}
