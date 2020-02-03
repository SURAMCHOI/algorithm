package d3;

import java.util.Scanner;

public class Solution_1209_sum {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		for(int tc=1;tc<=10;tc++) {
			int t=sc.nextInt();
			int answer=0;
			int map[][]=new int[100][100];
			for(int i=0;i<100;i++)
				for(int j=0;j<100;j++)
					map[i][j]=sc.nextInt();
			for(int i=0;i<100;i++) {
				int rsum=0;
				int csum=0;
				for(int j=0;j<100;j++) {
					rsum+=map[i][j];
					csum+=map[j][i];
				}
				answer=Math.max(Math.max(rsum,csum),answer);
			}
			int rdsum=0,ldsum=0;
			for(int i=0;i<100;i++)
			{
				rdsum+=map[i][i];
				ldsum+=map[99-i][99-i];
			}
			answer=Math.max(Math.max(rdsum,ldsum),answer);
			System.out.println("#"+t+" "+answer);
		}
	}

}
