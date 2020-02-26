

import java.util.Arrays;
import java.util.Scanner;

public class Solution_2999_비밀이메일 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		char [] arr=sc.next().toCharArray();
		int N=arr.length;

		int r=1,c=N;
		for(int i=1;i<=N;i++){
			if(N%i==0&&(N/i)<=i){
				r=Math.max(r, N/i);
				c=N/r;
			}
		}
		char msg[][]=new char [r][c];
		//세로방향으로 데이터 넣기 
		int index=0;
		for(int i=0;i<c;i++){
			for(int j=0;j<r;j++){
				msg[j][i]=arr[index];
				index++;
			}
		}
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				System.out.print(msg[i][j]);
			}
		}
		
	}
}
