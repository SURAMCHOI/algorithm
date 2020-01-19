#include<iostream>
using namespace std;
int checkstr(string str)
{
 int j=0; 
 for(int i=0;i<str.length();i++)
  {
    j=str.find(str.at(i),i+1);
	if(j!=-1&&j!=i+1)
		return 0;
		
  }
 return 1;
}
int main()
{
	int num;
	cin>>num;
	string str;
	int total=0;
	for(int i=0;i<num;i++)
	{	
		cin>>str;
		total+=checkstr(str);
	}
	cout<<total;
}
