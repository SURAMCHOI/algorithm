package backjoon;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Solution_1261_알고스팟 {
	static int N,M;
	static int map[][];
	static boolean visit[][];
	static int answer;
	public static void main(String[] args) throws Exception{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer(br.readLine()," ");
		M=Integer.parseInt(st.nextToken());
		N=Integer.parseInt(st.nextToken());
		map=new int [N][M];
		visit=new boolean [N][M];
		answer=Integer.MAX_VALUE;
		for(int i=0;i<N;i++) {
			String str=br.readLine();
			for(int j=0;j<M;j++) {
				map[i][j]=str.charAt(j)-'0';
			}
		}
		bfs();
		System.out.println(answer);
	}//end of main
	static class Room implements Comparable<Room>{
		int x;
		int y;
		int c;
		public Room(int x,int y,int c) {
			this.x=x;
			this.y=y;
			this.c=c;
		}
		@Override
		public int compareTo(Room o) {
			return Integer.compare(this.c, o.c);
		}
	}
	static int dir[][]= {{-1,0},{1,0},{0,-1},{0,1}};
	private static void bfs() {
		PriorityQueue<Room> pq=new PriorityQueue<>();
		pq.add(new Room(0,0,0));
		visit[0][0]=true;
		while(!pq.isEmpty()) {
			//System.out.println(pq.size());
			Room cur=pq.poll();
			if(cur.x==N-1&&cur.y==M-1) {
				answer=Math.min(answer, cur.c);
				continue;
			}
			if(cur.c>=answer) {
				continue;
			}
			for(int d=0;d<4;d++) {
				int nx=cur.x+dir[d][0];
				int ny=cur.y+dir[d][1];
				if(nx<0||nx>=N||ny<0||ny>=M) continue;
				if(!visit[nx][ny]) {
					int crash=cur.c;
					if(map[nx][ny]==1) {
						crash+=1;
					}
					visit[nx][ny]=true;
					pq.add(new Room(nx,ny,crash));
				}
			}
		}
	}
}//end of class 
