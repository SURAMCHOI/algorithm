

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution_1247_최적경로_최수람 {
	static int N,answer;
	static int route[][];
	static boolean visit[];
	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		System.setIn(new FileInputStream("1247_input.txt"));
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int T=Integer.parseInt(br.readLine().trim());
		for(int tc=1;tc<=T;tc++){
			N=Integer.parseInt(br.readLine());
			route=new int [N+2][2];
			visit=new boolean [N+2];
			answer=Integer.MAX_VALUE;
			StringTokenizer st=new StringTokenizer(br.readLine()," ");
			for(int i=0;i<N+2;i++){
				route[i][0]=Integer.parseInt(st.nextToken());
				route[i][1]=Integer.parseInt(st.nextToken());
			}
			for(int i=2;i<N+2;i++){
				int dist=Math.abs(route[0][0]-route[i][0])+Math.abs(route[0][1]-route[i][1]);
				visit[i]=true;
				dfs(0,i,1,dist);
				visit[i]=false;
			}
			System.out.println("#"+tc+" "+answer);
		}
	}
	private static void dfs(int c, int d, int cnt, int dist) {
		// TODO Auto-generated method stub
		if(cnt==N){
			int cd=Math.abs(route[d][0]-route[1][0])+Math.abs(route[d][1]-route[1][1]);
			answer=Math.min(answer, dist+cd);
			return ;
		}
		for(int i=2;i<N+2;i++){
			if(!visit[i]){
				int cd=Math.abs(route[d][0]-route[i][0])+Math.abs(route[d][1]-route[i][1]);
				visit[i]=true;
				dfs(d,i,cnt+1,dist+cd);
				visit[i]=false;
			}
		}
		
	}

}
