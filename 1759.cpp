#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<char> al;
vector<char> pw;
int l,c;
int v,co;
bool isvowel(int index)
{
	if(al[index]=='a' || al[index]=='e' || al[index]=='i'|| al[index]=='o'||al[index]=='u')
		return true;
	else 
		return false;
}
void dfs(int index,int num)
{
	pw.push_back(al[index]);
	if(num==l)
	{
		if(v>=1 && co>=2)
		{
		  for(int i=0;i<pw.size();i++)
		    	cout<<pw[i];
		  cout<<endl;
		}
		return ;
	}
	for(int i=index+1;i<c;i++)
    {
       if(isvowel(i))
	   {
		   v++;
		   dfs(i,num+1);
		   pw.pop_back();
		   v--;
	   }
	   else
	   {
		   co++;
		   dfs(i,num+1);
		   pw.pop_back();
		   co--;
	   }
	}

}
int main()
{
	cin>>l>>c;
	for(int i=0;i<c;i++)
    {
		char tmp;
		cin>>tmp;
		al.push_back(tmp);
	}
	sort(al.begin(),al.end());
	for(int i=0;i<=c-l;i++)
	{
	    if(isvowel(i))
		{	
			v=1;
			dfs(i,1);
			pw.pop_back();
			v=0;
		}
		else
		{
			co=1;
			dfs(i,1);
			pw.pop_back();
			co=0;
		}
	}


}
