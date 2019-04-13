#include<iostream>
#include<vector>
#include<algorithm>
//백준 1463번 1로 만들기 
using namespace std;

vector<int>m;

int makeOne(int n)
{
  if(n==1) return 0;
  if(m[n]!=-1) return m[n];
  if(n%6==0)
  {	
	  m[n]=min(makeOne(n/3)+1,makeOne(n/2)+1);
	  m[n]=min(makeOne(n-1)+1,m[n]);
  }
  else if(n%2==0)
      m[n]=min(makeOne(n/2)+1,makeOne(n-1)+1);
  else if(n%3==0)
	  m[n]=min(makeOne(n/3)+1,makeOne(n-1)+1);
  else
	  m[n]=makeOne(n-1)+1;
  return m[n];  
}
int main()
{
 int num;
 cin>>num;
 m.resize(num+1,-1);
 cout<<makeOne(num);
 return 0;
}
