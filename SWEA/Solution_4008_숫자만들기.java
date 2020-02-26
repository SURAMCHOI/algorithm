
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
//처음에 생각한 아이디어 : 2 1 0 1 -> 0 0 1 3 으로 순열 만들어서 완전탐색 -> 시간초과 ( 배열 크기가 늘어난만큼 재귀함수를 많이 호출해서,,?)
// 재귀함수로 바꿔서 완전탐색 

public class Solution_4008_숫자만들기 {
	static int N,max,min;
	static int[] nums;
	static int[] op;//0 : '+' 1: '-' 2: '*' 3:'/'
	static boolean start[];
	static boolean select[];
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		//System.setIn(new FileInputStream("4008_input.txt"));
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int T=Integer.parseInt(br.readLine());
		for(int tc=1;tc<=T;tc++){
			N=Integer.parseInt(br.readLine());
			nums=new int [N];
			op=new int [4];
			max=Integer.MIN_VALUE;
			min=Integer.MAX_VALUE;
			StringTokenizer st=new StringTokenizer(br.readLine()," ");
			int index=0;
			for(int i=0;i<4;i++){
				op[i]=Integer.parseInt(st.nextToken());
			}
			st=new StringTokenizer(br.readLine()," ");
			for(int i=0;i<N;i++)
				nums[i]=Integer.parseInt(st.nextToken());
			dfs(1,nums[0]);
			System.out.println("#"+tc+" "+(max-min));
		}
	}//end of main
	private static void dfs(int depth, int res) {
		// TODO Auto-generated method stub
		if(depth>=N){
			max=Math.max(max, res);
			min=Math.min(min, res);
			return ;
		}
		for(int i=0;i<4;i++){
			switch(i){
			case 0:
				if(op[0]>0){
					op[0]-=1;
					dfs(depth+1,res+nums[depth]);
					op[0]+=1;
				}
				break;
			case 1:
				if(op[1]>0){
					op[1]-=1;
					dfs(depth+1,res-nums[depth]);
					op[1]+=1;
				}
				break;
			case 2:
				if(op[2]>0){
					op[2]-=1;
					dfs(depth+1,res*nums[depth]);
					op[2]+=1;
				}
				break;
			case 3:
				if(op[3]>0){
					op[3]-=1;
					dfs(depth+1,res/nums[depth]);
					op[3]+=1;
				}
				break;
			}
		}
	}
}//end of class
