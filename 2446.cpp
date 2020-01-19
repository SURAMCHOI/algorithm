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
			for(int k=1;k<=i-1;k++)
				cout<<" ";
			for(int j=2*(num-(i-1))-1;j>0;j--)
				cout<<"*";
		}
		else
		{
		    for(int k=num-(i+1-num);k>0;k--)
				cout<<" ";
			for(int j=1;j<=2*(i-(num-1))-1;j++)
				cout<<"*";
		}
		cout<<"\n";
	}
}
