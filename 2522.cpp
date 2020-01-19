#include<iostream>
using namespace std;
int main()
{
	int num;
	cin>>num;
	for(int i=1;i<=2*num-1;i++)
	{
		if(i<=num)
		{
			for(int j=num-i;j>0;j--)
				cout<<" ";
			for(int k=1;k<=i;k++)
				cout<<"*";
		}
		else
		{
			for(int j=1;j<=i-num;j++)
				cout<<" ";
			for(int k=num-(i-num);k>0;k--)
				cout<<"*";
		}
		cout<<"\n";
	}
}
