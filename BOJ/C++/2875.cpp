#include<iostream>

using namespace std;
int w,m,intern;
int maketeam()
{
   int team=0;
   while(w>=2&&m>=1&&(w+m)>=3+intern)
   {
	   w-=2;
	   m-=1;
	   team++;
   }
  return team;

}
int main ()
{
	cin>>w>>m>>intern;
	cout<<maketeam()<<endl;

}
