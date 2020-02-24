#include<iostream>
using namespace std;
int reverse(int num)
{
	int tmp=0;
	int res=0;
	tmp=num%10;
	res+=tmp*100;
	num-=tmp;
	tmp=num%100;
	res+=tmp;
	tmp=num/100;
	res+=tmp;
	return res;
}
int main()
{
	int num1,num2;
	cin>>num1>>num2;
	num1=reverse(num1);
	num2=reverse(num2);
	if(num1>=num2)
		cout<<num1;
	else
		cout<<num2;
}
