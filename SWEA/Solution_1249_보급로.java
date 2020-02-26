

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;

public class Solution_1249_보급로{
	static int N;
	static int [][] map,dist;
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		System.setIn(new FileInputStream("1249_input.txt"));
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int T=Integer.parseInt(br.readLine().trim());
		for(int tc=1;tc<=T;tc++){
			N=Integer.parseInt(br.readLine().trim());
			map=new int [N][N];
			dist=new int [N][N]; 
			for(int i=0;i<N;i++){
				String line=br.readLine();
				for(int j=0;j<line.length();j++){
					map[i][j]=line.charAt(j)-'0';
					dist[i][j]=Integer.MAX_VALUE;
				}
			}
			System.out.println("#"+tc+" "+bfs());
		}
	}
	private static int bfs() {
		// TODO Auto-generated method stub
		LinkedList<int []> queue=new LinkedList<>();
		int dir[][]={{0,1},{1,0},{-1,0},{0,-1}};
		queue.offer(new int [] {0,0,0});
		while(!queue.isEmpty()){
			int cur[]=queue.poll();
			for(int d=0;d<4;d++){
				int nx=cur[0]+dir[d][0];
				int ny=cur[1]+dir[d][1];
				if(nx<0||nx>=N||ny<0||ny>=N) continue;
				int nextcost=cur[2]+map[nx][ny];
				if(nextcost>=dist[nx][ny]) continue;
				dist[nx][ny]=nextcost;
				queue.offer(new int []{nx,ny,nextcost});
			}
		}
		return dist[N-1][N-1];
	}
}
