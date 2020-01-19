#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<int> pos;
vector<int> neg;
bool desc(int a,int b)
{
	return a>b;
}
int main()
{
	int n;
	int one=0;
	int zero=0;
	cin>>n;
	int tmp;
	int ans=0;
	for(int i=0;i<n;i++)
	{
		cin>>tmp;
		if(tmp==1)
			one++;
		else if(tmp>0)
			pos.push_back(tmp);
		else if(tmp<0)
			neg.push_back(tmp);
		else
			zero++;
	}
	if(pos.size()!=0)
	  { 
		  sort(pos.begin(),pos.end(),desc);
		  int i=0;
		  for(i=0;i<pos.size()-1;i+=2)
		  { 
             ans+=pos[i]*pos[i+1];
		  }
		  if(i<pos.size())
			  ans+=pos[i];
	  }
	ans+=one;
	if(neg.size()!=0)
	{
	   sort(neg.begin(),neg.end());
	//음수 계산 
	   int i=0;
	   for(i=0;i<neg.size()-1;i+=2)
	   {
		ans+=neg[i]*neg[i+1];
	   }
	    if(i<neg.size())
	    {
        if(zero==0)
			ans+=neg[i];
	    }
	}
	cout<<ans<<endl;
}
