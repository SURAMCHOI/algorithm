

import java.util.Arrays;
import java.util.Scanner;

public class Solution_2819_격자판의숫자이어붙이기{
	static String nums[][];
	static boolean check[];
	static int answer;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		int T=sc.nextInt();
		for(int testcase=1;testcase<=T;testcase++){
			nums=new String [4][4];
			check=new boolean[10000000];
			for(int i=0;i<4;i++){
				for(int j=0;j<4;j++){
					nums[i][j]=sc.next();
				}
			}
			for(int i=0;i<4;i++){
				for(int j=0;j<4;j++){				
					makeNum(i,j,0,nums[i][j]);
				}
			}
			System.out.println("#"+testcase+" "+answer);
			answer=0;
			Arrays.fill(check, false);
		}
	}
	private static void makeNum(int x, int y, int cnt,String str) {
		// TODO Auto-generated method stub
		if(cnt==6){
			if(!check[Integer.valueOf(str)]){
				check[Integer.valueOf(str)]=true;
				answer++;
			}
			return ;
		}
		int dir[][]={{0,1},{0,-1},{1,0},{-1,0}};
		for(int i=0;i<4;i++){
			int nx=x+dir[i][0];
			int ny=y+dir[i][1];
			if(nx<0||nx>=4||ny<0||ny>=4)
				continue;
			makeNum(nx,ny,cnt+1,str+nums[nx][ny]);
		}
	}
}
