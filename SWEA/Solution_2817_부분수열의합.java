
import java.util.Scanner;

public class Solution_2817_부분수열의합{
	static int nums[];
	static int N,K;
	static int answer;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		int T=sc.nextInt();
		for(int testcase=1;testcase<=T;testcase++){
			N=sc.nextInt();
			K=sc.nextInt();
			nums=new int [N];
			for(int i=0;i<N;i++)
				nums[i]=sc.nextInt();
			for(int i=0;i<N;i++){
				select(i,nums[i]);
			}
			System.out.println("#"+testcase+" "+answer);
			answer=0;
		}
	}
	private static void select(int start, int sum) {
		// TODO Auto-generated method stub
		if(sum>K)
			return ;
		if(sum==K){
			answer++;
			return ;
		}
		for(int j=start+1;j<N;j++){
			select(j,sum+nums[j]);
		}
	}
}
