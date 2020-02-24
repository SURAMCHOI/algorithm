

import java.util.Scanner;

public class Solution_2805_농작물수확하기 {
	static int N;
	static int map[][];
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		int T=sc.nextInt();
		for(int testcase=1;testcase<=T;testcase++) {
			N=sc.nextInt();
			map=new int [N][N];
			for(int i=0;i<N;i++) {
				String str=sc.next();
				for(int j=0;j<str.length();j++)
					map[i][j]=str.charAt(j)-'0';
			}
			int answer=0;
			int middle=N/2;
			int j=N/2;
			for(int i=0;i<N;i++) {
				if(i<=middle) {
					int cnt=2*(i+1)-1;
					for(int k=0;k<cnt;k++) {
						answer+=map[i][j+k];	
					}
					j--;
					if(j==-1)
						j=0;
				}
				else
				{
					j++;
					int cnt=2*(N-i)-1;
					for(int k=0;k<cnt;k++) {
						answer+=map[i][j+k];	
					}
				}
			}
			System.out.println("#"+testcase+" "+answer);
		}
	}

}
