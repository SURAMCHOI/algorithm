package backjoon;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Solution_1309_동물원 {

	public static void main(String[] args) throws Exception{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int N=Integer.parseInt(br.readLine());
		long dp[][]=new long[3][N+1];
		dp[0][1]=1;
		dp[1][1]=1;
		dp[2][1]=1;
		for(int i=2;i<=N;i++) {
			dp[0][i]=(dp[0][i-1]+dp[1][i-1]+dp[2][i-1])%9901;
			dp[1][i]=(dp[0][i-1]+dp[2][i-1])%9901;
			dp[2][i]=(dp[0][i-1]+dp[1][i-1])%9901;
		}
		long answer=0;
		for(int i=0;i<3;i++) {
			answer=(answer+dp[i][N])%9901;
		}
		System.out.println(answer%9901);
	}//end of main
}//end of class 
