

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Solution_1953_탈주범검거 {
	static int N,M,R,C,L,answer;
	static int[][] map;
	static boolean [][] visit;
	public static void main(String[] args)  throws Exception{
		// TODO Auto-generated method stub
		//System.setIn(new FileInputStream("1953_input.txt"));
		BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
		int T= Integer.parseInt(br.readLine());
		for(int tc=1;tc<=T;tc++){
			StringTokenizer st=new StringTokenizer(br.readLine()," ");
			N=Integer.parseInt(st.nextToken());
			M=Integer.parseInt(st.nextToken());
			R=Integer.parseInt(st.nextToken());
			C=Integer.parseInt(st.nextToken());
			L=Integer.parseInt(st.nextToken());
			answer=0;
			map=new int [N][M];
			visit=new boolean [N][M];
			for(int i=0;i<N;i++){
				st=new StringTokenizer(br.readLine()," ");
				for(int j=0;j<M;j++){
					map[i][j]=Integer.parseInt(st.nextToken());
				}
			}
			bfs();
			System.out.println("#"+tc+" "+answer);
		} 
	}//end of main
	static int dir[][]={{-1,0},{1,0},{0,-1},{0,1}};//0: 상  1: 하    2:좌    3: 우
	static int[][] t={{0,0},{0,1,2,3},{0,1},{2,3},{0,3},{1,3},{1,2},{0,2}};
	private static void bfs() {
		// TODO Auto-generated method stub
		LinkedList<int [] > q=new LinkedList<>();
		q.offer(new int [] {R,C});
		visit[R][C]=true;
		answer++;
		int time=2;
		while(!q.isEmpty()){
			if(time>L)
				break;
			int qlen=q.size();
			for(int i=0;i<qlen;i++){
				int []cur=q.poll();
				int x=cur[0];
				int y=cur[1];
				int num=map[x][y];
				int size=t[num].length;
				for(int k=0;k<size;k++){
					int d=t[num][k];
					int nx=x+dir[d][0];
					int ny=y+dir[d][1];
					if(0>nx || nx>=N || 0>ny|| ny>=M) continue;
					if(map[nx][ny]!=0 && !visit[nx][ny]){
						if(isConnect(d,nx,ny)){
							visit[nx][ny]=true;
							answer++;
							q.offer(new int [] {nx,ny});							
						}
					}
				}
			}
			time++;
		}
	}
	private static boolean isConnect(int d, int x, int y) {
		// TODO Auto-generated method stub
		int td=0;
		switch(d){
		case 0:
			td=1;
			break;
		case 1:
			td=0;
			break;
		case 2:
			td=3;
			break;
		case 3:
			td=2;
			break;
		}
		int num=map[x][y];
		int size=t[num].length;
		for(int i=0;i<size;i++)
			if(t[num][i]==td)
				return true;
		return false;
	}
}//end of class

