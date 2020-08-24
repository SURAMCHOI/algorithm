
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Solution_1486_장훈이의높은선반 {
	static int N,B,answer;
	static int[] nums;
	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		//System.setIn(new FileInputStream("1486_input.txt"));
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int T=Integer.parseInt(br.readLine());
		for(int tc=1;tc<=T;tc++){
			StringTokenizer st=new StringTokenizer(br.readLine()," ");
			N=Integer.parseInt(st.nextToken());
			B=Integer.parseInt(st.nextToken());
			nums=new int [N];
			answer=Integer.MAX_VALUE;
			st=new StringTokenizer(br.readLine()," ");
			for(int i=0;i<N;i++){
				nums[i]=Integer.parseInt(st.nextToken());
			}
			Arrays.sort(nums);
			for(int i=0;i<N;i++){
				dfs(i,nums[i]);
			}
			System.out.println("#"+tc+" "+answer);
		}//end of tc
	}//end of main
	private static void dfs(int start, int sum) {
		if(sum>=B){
			answer=Math.min(answer, sum-B);
			return ;
		}
		else if(sum<B){
			for(int i=start+1;i<N;i++){
				dfs(i,sum+nums[i]);
			}
		}
	}
}//end of class 
