#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<vector <int> > A;
vector<pair<int,int> > con;
int r,c,k;
int ans=0;
void find_num(int num)
{
	bool flag=false;
	for(int i=0;i<con.size();i++)
	{
		if(con[i].second==num)
		{	
			con[i].first++;
			flag=true;
		}
	}
	if(!flag)
		con.push_back(make_pair(1,num));
}
void my_resize(int row,int col)
{
	A.clear();
	for(int i=0;i<row;i++)
	{
		vector<int> tmp;
		tmp.resize(col,0);
		A.push_back(tmp);
	}
}
void r_cal(int row,int col)
{
   vector<vector<int> > result;
   vector<int> tmp;
   for(int i=0;i<row;i++)
   {
	 tmp.clear();
	 con.clear();
	 for(int j=0;j<col;j++)
	 {
	     if(A[i][j]==0) continue;
		 find_num(A[i][j]);
	 }
     sort(con.begin(),con.end());
     for(int k=0;k<con.size();k++)
	 {
		 tmp.push_back(con[k].second);
		 tmp.push_back(con[k].first);
	 }
     result.push_back(tmp);
   }
   int ncol=0;
   for(int i=0;i<result.size();i++)
   {
	   if(ncol<result[i].size())
		   ncol=result[i].size();
   }
   my_resize(row,ncol);
   for(int i=0;i<result.size();i++)
   {
	   for(int j=0;j<result[i].size();j++)
	   {	  
		   A[i][j]=result[i][j];   
	   }
   }
}
void c_cal(int row,int col)
{
   vector<vector<int> > result;
   vector<int> tmp;
   for(int i=0;i<col;i++)
   {
	   tmp.clear();
	   con.clear();
	   for(int j=0;j<row;j++)
	   {
		   if(A[j][i]==0) continue;
		   find_num(A[j][i]);
	   }
	   sort(con.begin(),con.end());
	   for(int k=0;k<con.size();k++)
	   {
		   tmp.push_back(con[k].second);
		   tmp.push_back(con[k].first);
	   }
	   result.push_back(tmp);
   }
   int nrow=0;
   for(int i=0;i<result.size();i++)
   {
	   if(nrow<result[i].size())
		   nrow=result[i].size();
   }
   my_resize(nrow,col);
   for(int i=0;i<result.size();i++)
	   for(int j=0;j<result[i].size();j++)
		   A[j][i]=result[i][j];
}
void find_ans()
{
   while(1)
   {
	  int row=A.size();
	  int col=A[0].size();
      if(r-1 <row && c-1 <<col)
	  {
	    if(A[r-1][c-1]==k)
		  return ;
	  }
	  if(ans>=100)
	  {
		 ans=-1;
    	 return ;
	  }
	  if(row>=col)
	  {	  
		  r_cal(row,col);
		  ans++;
	  }
	  else 
	  {	  
		  c_cal(row,col);
		  ans++;
	  }
  }

}
int main()
{
  cin>>r>>c>>k;
  my_resize(3,3);
  for(int i=0;i<3;i++)
  {
	  for(int j=0;j<3;j++)
		  cin>>A[i][j];
  }
  find_ans();
  cout<<ans<<endl;
}
