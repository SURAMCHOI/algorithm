
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Solution_17616_등수찾기 {
	static int cnt,N,M,X;
	static int [] high_rank,lower_rank;
	static int [][] info;
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer(br.readLine()," ");
		N=Integer.parseInt(st.nextToken());
		M=Integer.parseInt(st.nextToken());
		X=Integer.parseInt(st.nextToken());
		high_rank=new int [N+1];
		info=new int [M][2]; 
		lower_rank=new int [N+1];
		for(int i=0;i<M;i++){
			st=new StringTokenizer(br.readLine()," ");
			info[i][0]=Integer.parseInt(st.nextToken());
			info[i][1]=Integer.parseInt(st.nextToken());
		}
		Arrays.sort(info,new Comparator<int []>() {

			@Override
			public int compare(int[] o1, int[] o2) {
				// TODO Auto-generated method stub
				return o1[0]-o2[0];
			}
		});
		//higher rank 채우기 
		for(int i=0;i<M;i++){
			int u=info[i][0];
			int v=info[i][1];
			high_rank[v]=Math.max(high_rank[u]+1,high_rank[v]+1);
		}
		//lower rank 채우기 
		for(int i=0;i<M;i++)
		{
			cnt=1;
			int u=info[i][0];
			int v=info[i][1];
			bfs(v);
			lower_rank[u]=cnt;
			
		}
		int min=high_rank[X]+1;
		int max=N-lower_rank[X];
		System.out.println(min+" "+max);
	}// end of main
	//bfs로 점수가 낮은 학생수 구하기 
	private static void bfs(int v) {
		// TODO Auto-generated method stub
		boolean visit[]=new boolean [N+1];
		
	}

}//end of class 
