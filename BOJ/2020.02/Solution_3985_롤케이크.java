

import java.util.Scanner;

public class Solution_3985_롤케이크 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		int L=sc.nextInt();
		int N=sc.nextInt();
		int c[][]=new int [N+1][3];
		//고객이 원하는 조각을 표시할 배열 
		int cake[]=new int [L+1];
		//가장 많은 조각을 받도록 예상되는 방청객 
		int max=0;
		int maxIndex=0;
		for(int i=1;i<=N;i++){
			c[i][0]=sc.nextInt();
			c[i][1]=sc.nextInt();
			if(max<(c[i][1]-c[i][0])+1){
				max=(c[i][1]-c[i][0])+1;
				maxIndex=i;
			}
			if(max==(c[i][1]-c[i][0])+1){
				if(maxIndex>i)
					maxIndex=i;
			}
		}
		for(int i=1;i<=N;i++){
			for(int j=c[i][0];j<=c[i][1];j++){
				if(cake[j]==0){
					cake[j]=i;
					c[i][2]++;
				}
			}
		}
		int realmax=0;
		int realc=0;
		for(int i=1;i<=N;i++){
			if(c[i][2]>realmax){
				realmax=c[i][2];
				realc=i;
			}
		}
		System.out.println(maxIndex);
		System.out.println(realc);
	}
}
