#include<iostream>
#include<cstdio>
#include<algorithm>

#define N 9
#define MAX 100

using namespace std;

int sum(int *arr)
{
	int sum=0;
	for(int i=0;i<N;i++)
		sum+=arr[i];
	return sum;
}

int solution(int sum,int *arr)
{
	for(int i=0;i<N-1;i++)
		for(int j=i+1;j<N;j++)
			if(sum-(arr[i]+arr[j])==MAX)
			{
				arr[i]=-1;
				arr[j]=-1;
				return 0;
			}
}

int main()
{
  int arr[N];
  for(int i=0;i<N;i++)
	  scanf("%d",arr+i);
  int ssum=sum(arr);
  solution(ssum,arr);
  sort(arr,arr+N);
  for(int i=2;i<N;i++)
  {	 
		  printf("%d\n",arr[i]);
  }
 return 0;
}

