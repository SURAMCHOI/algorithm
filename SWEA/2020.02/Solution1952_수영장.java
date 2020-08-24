
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/*
 * 처음 아이디어 : 1일 vs 1달 비교 -> 3달 비교 -> 1년 비교  ==> 47/50
 * 순차적으로 비교하는 것이 최적이 아닐 수 있음
 * 
 * 수정한 아이디어 : 완전탐색 
 */

public class Solution1952_수영장 {
	static int [] plan;
	static int [] fee; //1일 1달 3달 1년 
	static int answer;
	public static void main(String[] args) throws Exception {
	//System.setIn(new FileInputStream("1952_input.txt"));
	BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	int T=Integer.parseInt(br.readLine());
	for(int tc=1;tc<=T;tc++){
		plan=new int [13];
		fee=new int [5];
		answer=Integer.MAX_VALUE;
		StringTokenizer st=new StringTokenizer(br.readLine()," ");
		for(int i=1;i<=4;i++){
			fee[i]=Integer.parseInt(st.nextToken());
		}
		st=new StringTokenizer(br.readLine()," ");
		for(int i=1;i<=12;i++){
			plan[i]=Integer.parseInt(st.nextToken());
		}
		//1일권 선택
		dfs(1,2,plan[1]*fee[1]);
		//1달권 선택 
		if(plan[1]!=0){
			dfs(1,2,fee[2]);
			//3달권 선택 
			dfs(1,4,fee[3]);			
		}
		answer=Math.min(answer, fee[4]);
		System.out.println("#"+tc+" "+answer);
	}//end of tc
	}//end of main
	private static void dfs(int start, int next, int sum) {
		// TODO Auto-generated method stub
		if(next>12){
			answer=Math.min(answer, sum);
			return ;
		}
		dfs(next,next+1,sum+plan[next]*fee[1]);
		if(plan[next]!=0){
			dfs(next,next+1,sum+fee[2]);
			dfs(next,next+3,sum+fee[3]);
		}
	}
}//end of class
