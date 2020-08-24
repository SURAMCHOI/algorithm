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
			for(int j=1;j<=i;j++)
				cout<<"*";
			for(int k=2*num-2*i;k>0;k--)
				cout<<" ";
			for(int n=1;n<=i;n++)
				cout<<"*";
		}
		else
		{
			for(int j=2*num-i;j>0;j--)
				cout<<"*";
			for(int k=2*i-2*num;k>0;k--)
				cout<<" ";
			for(int n=2*num-i;n>0;n--)
				cout<<"*";
		}
		cout<<"\n";
	}
}
