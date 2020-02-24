#include<iostream>
using namespace std;
int n,m;
int mat[500][500];
int check[4][4]={{0,-1},{0,1},{-1,0},{1,0}};

int findmax()
{
  int max=0;
	  
		  

}
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>mat[i][j];
	cout<<findmax();
}
