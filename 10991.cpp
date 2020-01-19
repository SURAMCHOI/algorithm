#include<iostream>
using namespace std;
int main()
{
	int num;
	cin>>num;
	for(int i=1;i<=num;i++)
	{
		for(int j=num-i;j>0;j--)
			cout<<" ";
		for(int k=1;k<=2*i-1;k++)
		{
			if(k%2==1)
				cout<<"*";
			else
				cout<<" ";
		}
		cout<<"\n";

	}
}
