

import java.util.Scanner;

public class Solution_2563_색종이 {
	static int p[][];
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		int N=sc.nextInt();
		p=new int [101][101];
		for(int i=0;i<N;i++){
			int x=sc.nextInt();
			int y=sc.nextInt();
			fill(x,y);
		}
		int answer=0;
		for(int i=1;i<=100;i++){
			for(int j=1;j<=100;j++){
				if(p[i][j]==1){
					answer+=1;
				}
			}
		}
		System.out.println(answer);
	}

	private static void fill(int x, int y) {
		// TODO Auto-generated method stub
		for(int i=0;i<10;i++){
			for(int j=0;j<10;j++){
				p[x+i][y+j]=1;
			}
		}
	}
}
