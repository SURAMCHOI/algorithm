package backjoon;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Solution_17616_등수찾기 {
	static int N,M,X;	
	public static void main(String[] args) throws Exception{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer(br.readLine()," ");
		int u=0,v=0;
		N=Integer.parseInt(st.nextToken());
		M=Integer.parseInt(st.nextToken());
		X=Integer.parseInt(st.nextToken());
		LinkedList<Integer>[] front=new LinkedList[N+1];
		LinkedList<Integer>[] back=new LinkedList[N+1];;		
		boolean exist[]=new boolean[N+1];
		for(int i=1;i<=N;i++) {
			front[i]=new LinkedList<>();
			back[i]=new LinkedList<>();
		}
		for(int i=0;i<M;i++) {
			st=new StringTokenizer(br.readLine()," ");
			int v1=Integer.parseInt(st.nextToken());
			int v2=Integer.parseInt(st.nextToken());
			front[v2].add(v1);
			back[v1].add(v2);
			exist[v1]=true;
			exist[v2]=true;
		}
		if(exist[X]==false) {
			u=1;
			v=N;
		}else {
			//front bfs
			int f=bfs(front);
			//back bfs
			int b=bfs(back);
			u=f+1;
			v=N-b;
		}
		System.out.println(u+" "+v);
	}//end of main
	private static int bfs(LinkedList<Integer>[] adj) {
		Queue<Integer> q=new LinkedList<>();
		boolean visit[]=new boolean[N+1];
		q.add(X);
		visit[X]=true;
		int num=0;
		while(!q.isEmpty()) {
			int idx=q.poll();
			for (int next : adj[idx]) {
				if(!visit[next]) {
					num++;
					q.add(next);
					visit[next]=true;
				}
			}
		}
		return num;
	}
}//end of class 
