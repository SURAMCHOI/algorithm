#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
struct shark 
{
  int x;
  int y;
  int s;
  int d;
  int z;
};
vector<shark> vs;
int r,c,m;
int ans=0;
int arr[5][2]={{0,0},{-1,0},{1,0},{0,1},{0,-1}};
int check(int x,int y)
{
    if(x>=1 && x<=r && y>=1 && y<=c)
		return true;
	else 
		return false;
}
void catch_shark(int col)
{
	int sz=0;
	int dis=120;
	bool c=false;
	int index;
	for(int i=0;i<vs.size();i++)
	{
	   if(vs[i].y==col)
	   {
		  c=true;
		  if(dis>vs[i].x)
		  {
             dis=vs[i].x;
			 sz=vs[i].z;
			 index=i;
		  }
	   }
	}
	if(c)
	{
		vs.erase(vs.begin()+index);
		ans+=sz;
		
	}
}
void find_shark()
{
   for(int i=0;i<vs.size();i++)
   {
	   int x=vs[i].x;
	   int y=vs[i].y;
	   for(int j=0;j<vs.size();j++)
	   {
	     if(i==j) continue;
		 if(x==vs[j].x && y==vs[j].y)
	    { 
			if(vs[i].z > vs[j].z)
			   vs.erase(vs.begin()+j);
		   else
			   vs.erase(vs.begin()+i);
	    }
	  }
   }
}
void move_shark()
{
	for(int i=0;i<vs.size();i++)
	{
	   int d=vs[i].d;
	   int x=vs[i].x;
	   int y=vs[i].y;
	   int s=vs[i].s;
//	   cout<<"before : "<<"index : "<<i<<"x: "<<x<<"y: "<<y<<endl;
	   while(s!=0)
	   {
		  if(check(x+arr[d][0],y+arr[d][1]))
		  {
			  x+=arr[d][0];
			  y+=arr[d][1];
			  s--;
		  }
		  else
		  {
			  switch(d)
			  {
				  case 1:
					  d=2;
					  break;
				  case 2:
					  d=1;
					  break;
				  case 3:
					  d=4;
					  break;
				  case 4:
					  d=3;
					  break;
			 }
		  }
	  }
	   vs[i].x=x;
	   vs[i].y=y;
	   vs[i].d=d;
//	   cout<<"after: "<<"x : "<<x<<"y: "<<y<<endl;
	}
}
void fishing()
{
  for(int i=1;i<=c;i++)
  {
	 catch_shark(i);
	 move_shark();
	 find_shark();
  }
}
int main()
{
  cin>>r>>c>>m;
  vs.resize(m);
  for(int i=0;i<m;i++)
  {
     cin>>vs[i].x>>vs[i].y>>vs[i].s>>vs[i].d>>vs[i].z;

  }
  if(m>=1)
   fishing();
  cout<<ans<<endl;


}
