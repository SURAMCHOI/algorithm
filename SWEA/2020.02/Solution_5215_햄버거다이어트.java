

import java.util.Scanner;

public class Solution_5215_햄버거다이어트 {
	static int cal[];
	static int taste[];
	static int answer,N,L;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		int T=sc.nextInt();
		for(int testcase=1;testcase<=T;testcase++) {
			N=sc.nextInt();
			L=sc.nextInt();
			taste=new int [N];
			cal=new int [N];
			for(int i=0;i<N;i++) {
				taste[i]=sc.nextInt();
				cal[i]=sc.nextInt();
			}
			for(int i=0;i<N;i++) {
				select(i,taste[i],cal[i]);				
			}
			System.out.println("#"+testcase+" "+answer);
			answer=0;
		}
	}
	private static void select(int start,int tsum,int csum) {
		// TODO Auto-generated method stub
		if(csum>L)
			return;
		else if(csum<=L) {
			answer=Math.max(answer, tsum);
			for(int i=start+1;i<N;i++)
				select(i,tsum+taste[i],csum+cal[i]);
		}
			
	}

}
