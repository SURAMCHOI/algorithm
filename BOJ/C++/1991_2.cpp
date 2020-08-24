#include<iostream>

using namespace std;
struct node
{
	char left;
	char right;
};
struct node tree[100];
int n;
void preorder(char node)
{
   cout<<node;
   if(tree[node-'0'].left!='.')
     preorder(tree[node-'0'].left);
   if(tree[node-'0'].right!='.')
     preorder(tree[node-'0'].right);
}
void midorder(char node)
{
   if(tree[node-'0'].left!='.')
	   midorder(tree[node-'0'].left);
   cout<<node;
   if(tree[node-'0'].right!='.')
	   midorder(tree[node-'0'].right);
}
void postorder(char node)
{	
	if(tree[node-'0'].left!='.')
		postorder(tree[node-'0'].left);
	if(tree[node-'0'].right!='.')
		postorder(tree[node-'0'].right);
	cout<<node;
}
int main()
{
	cin>>n;
	char t1,t2,t3;
	for(int i=0;i<n;i++)
	{
      cin>>t1>>t2>>t3;
	  tree[t1-'0'].left=t2;
	  tree[t1-'0'].right=t3;
	}
	preorder('A');
	cout<<endl;
	midorder('A');
	cout<<endl;
	postorder('A');
	cout<<endl;

}
