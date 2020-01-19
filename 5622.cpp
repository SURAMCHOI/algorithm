#include<iostream>
using namespace std;
int main()
{
  string num;
  cin>>num;
  int total=0;
  int tmp=0;
  for(int i=0;i<num.length();i++)
  {
	  if(num.at(i)=='A'||num.at(i)=='B'||num.at(i)=='C')
		  tmp=2;
	  if(num.at(i)=='D'||num.at(i)=='E'||num.at(i)=='F')
		  tmp=3;
	  if(num.at(i)=='G'||num.at(i)=='H'||num.at(i)=='I')
		  tmp=4;
	  if(num.at(i)=='J'||num.at(i)=='K'||num.at(i)=='L')
		  tmp=5;
	  if(num.at(i)=='M'||num.at(i)=='N'||num.at(i)=='O')
		  tmp=6;
	  if(num.at(i)=='P'||num.at(i)=='Q'||num.at(i)=='R'||num.at(i)=='S')
		  tmp=7;
	  if(num.at(i)=='T'||num.at(i)=='U'||num.at(i)=='V')
		  tmp=8;
	  if(num.at(i)=='W'||num.at(i)=='X'||num.at(i)=='Y'||num.at(i)=='Z')
		  tmp=9;
	  tmp=11-(10-tmp);
	  total+=tmp;
  }
 cout<<total;
}

