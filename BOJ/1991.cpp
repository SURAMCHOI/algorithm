#include<iostream>
#include<vector>
using namespace std;
struct node 
{
	char left;
	char right;
};

struct node tree[100];
int n;

void pre_order(char root) //전위 순회 
{
    if(root == '.')
		return ;
	cout<<root;
	pre_order(tree[root].left);
	pre_order(tree[root].right);
}
void in_order(char root)
{
	if(root == '.')
		return ;
	in_order(tree[root].left);
	cout<<root;
	in_order(tree[root].right);
}
void post_order(char root)
{
	if(root=='.')
		return ;
	post_order(tree[root].left);
	post_order(tree[root].right);
	cout<<root;
}
int main ()
{
	cin>>n;
	char t1,t2,t3;
	for(int i=0;i<n;i++)
	{
		cin>>t1>>t2>>t3;
		tree[t1].left=t2;
		tree[t1].right=t3;
	}
	pre_order('A');
	cout<<endl;
	in_order('A');
	cout<<endl;
	post_order('A');
}

