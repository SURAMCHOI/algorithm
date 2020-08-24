#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int n;
vector<int> neg;
vector<int> pos;

bool desc(int a,int b)
{	
	return a>b;
}
int main()
{
	cin>>n;
	int zero=0;
	int one=0;
	int ans=0;
	for(int i=0;i<n;i++)
	{
       int num;
	   cin>>num;
	   if(num==0)
		   zero++;
	   else if(num==1)
		   one++;
	   else if(num>0)
		   pos.push_back(num);
	   else if(num<0)
		   neg.push_back(num);
	}
	if(pos.size()!=0)
	{
      sort(pos.begin(),pos.end(),desc);
	  int i;
	  for(i=0;i<pos.size()-1;i+=2)
          ans+=pos[i]*pos[i+1];
	  if(i<pos.size())
		  ans+=pos[i];
	}
	ans+=one;
	if(neg.size()!=0)
	{
		sort(neg.begin(),neg.end());
		int i;
		for(i=0;i<neg.size()-1;i+=2)
			ans+=neg[i]*neg[i+1];
		if(i<neg.size())
		{	
			if(zero==0)
			 ans+=neg[i];
		}
            
	}
	cout<<ans<<endl;
}
