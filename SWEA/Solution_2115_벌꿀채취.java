
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Solution_2115_벌꿀채취 {
	static int N,M,C,answer;
	static int map [][];
	static ArrayList<Integer> h;
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		//System.setIn(new FileInputStream("2115_input.txt"));
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int T=Integer.parseInt(br.readLine());
		for(int tc=1;tc<=T;tc++){
			StringTokenizer st=new StringTokenizer(br.readLine()," ");
			N=Integer.parseInt(st.nextToken());
			M=Integer.parseInt(st.nextToken());
			C=Integer.parseInt(st.nextToken());
			map=new int [N][N];
			answer=0;
			h=new ArrayList<>();
			for(int i=0;i<N;i++){
				st=new StringTokenizer(br.readLine()," ");
				for(int j=0;j<N;j++){
					map[i][j]=Integer.parseInt(st.nextToken());
				}
			}
			for(int i=0;i<N;i++){
				for(int j=0;j+(M-1)<N;j++){
					//System.out.println("조합  "+" "+i+" "+j+" "+(j+(M-1)));
					int s=cal(i,j,j+(M-1));
					dfs(1,i,j,j+(M-1),s);
				}
			}
			System.out.println("#"+tc+" "+answer);
		}
	}//end of main
	private static void dfs(int cnt,int row,int scol,int ecol,int sum) {
		// TODO Auto-generated method stub
		if(cnt==2){
			answer=Math.max(answer, sum);
			return ;
		}
		for(int i=row;i<N;i++){
			for(int j=0;j+(M-1)<N;j++){
				if(i==row &&j<=ecol) continue;
				//System.out.println("조합  "+cnt+" "+i+" "+j+" "+(j+(M-1)));
				int s=cal(i,j,j+(M-1));
				dfs(cnt+1,i,j,j+(M-1),sum+s);
			}
		}
	}
	private static int cal(int row, int start, int end) {
		// TODO Auto-generated method stub
		int max=0;
		int n=(end-start)+1;
		for(int i=1,size=1<<n;i<size;i++){
			int profit=0;
			int sum=0;			
			for(int j=0;j<n;j++){
				if((i&1<<j)!=0){
					sum+=map[row][start+j];
					h.add(map[row][start+j]);
				}
			}
			if(sum<=C){
				for(int it=0;it<h.size();it++){
					profit+=Math.pow(h.get(it), 2);
				}
				max=Math.max(max, profit);
			}
			h.clear();
		}
		return max;
	}
}//end of class
