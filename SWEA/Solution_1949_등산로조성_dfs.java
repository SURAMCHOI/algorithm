

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.StringTokenizer;

import javax.swing.plaf.synth.SynthSeparatorUI;

//시간초과로 실패
public class Solution_1949_등산로조성_dfs {
	static int N,K,answer;
	static int[][] map;
	static boolean visited[][];
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		System.setIn(new FileInputStream("1949_input.txt"));
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int T=Integer.parseInt(br.readLine().trim());
		for(int tc=1;tc<=T;tc++) {
			answer=0;
			StringTokenizer st=new StringTokenizer(br.readLine());
			N=Integer.parseInt(st.nextToken());
			map=new int [N][N];
			visited=new boolean [N][N];
			int max=0;
			K=Integer.parseInt(st.nextToken());
			for(int i=0;i<N;i++) {
				st=new StringTokenizer(br.readLine());
				for(int j=0;j<N;j++) {
					map[i][j]=Integer.parseInt(st.nextToken());
					max=Math.max(max, map[i][j]);
				}
			}
			for(int i=0;i<N;i++){
				for(int j=0;j<N;j++){
					if(max==map[i][j]&&!visited[i][j]){
						visited[i][j]=true;
						dfs(i,j,map[i][j],1,false);
						visited[i][j]=false;
					}
				}
			}	
			System.out.println("#"+tc+" "+answer);
		}
	}
	/**
	 * 
	 * @param x
	 * @param y
	 * @param num ���� ���츮 ��
	 * @param cnt ������� �̵��� �Ÿ� 
	 * @param k ��⸦ �����ߴ��� ���� 
	 */
	private static void dfs(int x, int y, int num,int cnt, boolean k) {
		// TODO Auto-generated method stub
		//��������� �Ÿ��� �ִ밪���� ������
		answer=Math.max(answer,cnt);
		int dir[][]= {{1,0},{0,1},{-1,0},{0,-1}};
		for(int d=0;d<4;d++) {
			int nx=x+dir[d][0];
			int ny=y+dir[d][1];
			if(nx<0||nx>=N||ny<0||ny>=N) continue;
			if(visited[nx][ny]) continue;
				//�̵����� ���ϴ� ��� ��� �����ϱ� 
			if(num<=map[nx][ny]) {
				if(!k){
					for(int depth=1;depth<=K;depth++){
						int tmp=map[nx][ny];
						int newland=map[nx][ny]-depth;
						if(map[x][y]>newland){
							visited[nx][ny]=true;
							dfs(nx,ny,map[nx][ny]-depth,cnt+1,true);
							visited[nx][ny]=false;
						}
					}
				}
			}
			else {
					visited[nx][ny]=true;
					dfs(nx,ny,map[nx][ny],cnt+1,k);	
					visited[nx][ny]=false;
				}
		}		
	}
}


