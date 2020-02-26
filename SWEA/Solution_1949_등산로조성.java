

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.StringTokenizer;



class Node{
	int x;
	int y;
	int num;
	int cnt;
	boolean k;
	//num = ���� ��ǥ�� ���� , cnt = ��������� �Ÿ� 
	public Node(int x, int y,int num, int cnt,boolean k) {
		this.x = x;
		this.y = y;
		this.num=num;
		this.cnt = cnt;
		this.k=k;
	}	
}

public class Solution_1949_등산로조성 {
	static int N,K,answer;
	static int[][] map,dist;
	static boolean[][] visited;
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
			dist=new int [N][N];
			visited=new boolean[N][N];
			K=Integer.parseInt(st.nextToken());
			int max=0;
			for(int i=0;i<N;i++) {
				st=new StringTokenizer(br.readLine());
				for(int j=0;j<N;j++) {
					map[i][j]=Integer.parseInt(st.nextToken());
					max=Math.max(max, map[i][j]);
					
				}
			}
			bfs(max);
			System.out.println("#"+tc+" "+answer);
		}
	}
	private static void bfs(int max) {
		// TODO Auto-generated method stub
		LinkedList<Node> queue=new LinkedList<>();
		int dir[][]= {{1,0},{0,1},{-1,0},{0,-1}};
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				if(map[i][j]==max)
					queue.offer(new Node(i,j,map[i][j],0,false));
			}
		}
		while(!queue.isEmpty()) {
			Node cur=queue.poll();
			if(map[cur.x][cur.y]!=max&&dist[cur.x][cur.y]>cur.cnt)
				continue;
			boolean conti=false;
			for(int d=0;d<4;d++) {
				boolean sub=false;
				int nx=cur.x+dir[d][0];
				int ny=cur.y+dir[d][1];
				int k=1;
				if(nx<0||nx>=N||ny<0||ny>=N) continue;
				//�̵����� ���ϴ� ��� ��� �����ϱ� 
				if(cur.num<=map[nx][ny]) {
					if(cur.k)
						continue;
					while(k<=K) {
						if(cur.num>(map[nx][ny]-k)) {
							sub=true;
							break;
						}
						k++;
					}
					if(k>K)
						continue;
				}
				//������ ���� ������ ��� 
				if(dist[nx][ny]<cur.cnt+1) {
					dist[nx][ny]=cur.cnt+1;
					conti=true;
					if(sub) {
						queue.offer(new Node(nx,ny,map[nx][ny]-k,cur.cnt+1,true));						
					}else {
						queue.offer(new Node(nx,ny,map[nx][ny],cur.cnt+1,cur.k));												
					}
				}
			}
			if(!conti) {
				answer=Math.max(answer,cur.cnt+1);
			}
		}
	}
}

