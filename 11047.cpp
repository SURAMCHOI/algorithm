#include<iostream>
#include<vector>

using namespace std;

vector<int> coin;
int n,k;

int findcnt()
{
   int cnt=0;
   int index=n;
   while(k!=0)
   {
	   if(coin[index]>k)
		   index--;
	   else
	   {
		   k-=coin[index];
		   cnt++;
	   }
	   
   }
  return cnt;

}
int main()
{
  cin>>n>>k;
  coin.resize(n+1,0);
  for(int i=1;i<=n;i++)
  {
      cin>>coin[i];
  }
  cout<<findcnt()<<endl;
}
