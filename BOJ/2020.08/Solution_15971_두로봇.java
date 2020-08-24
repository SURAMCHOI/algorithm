package backjoon;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Solution_15971_두로봇{
	static int N;
	static int answer;
	static class Node{
		int idx;
		int cost;
		public Node(int idx,int cost) {
			this.idx=idx;
			this.cost=cost;
		}
	}
	static int room1,room2;
	static List<Node>[] adj;
	static List<Integer>costs;
	public static void main(String[] args) throws Exception{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer(br.readLine()," ");
		N=Integer.parseInt(st.nextToken());
		room1=Integer.parseInt(st.nextToken())-1;
		room2=Integer.parseInt(st.nextToken())-1;
		adj=new List[N];
		costs=new LinkedList<>();
		for(int i=0;i<N;i++) {
			adj[i]=new LinkedList<Node>();
		}
		for(int i=0;i<N-1;i++) {
			st=new StringTokenizer(br.readLine()," ");
			int r1=Integer.parseInt(st.nextToken())-1;
			int r2=Integer.parseInt(st.nextToken())-1;
			int cost=Integer.parseInt(st.nextToken());
			adj[r1].add(new Node(r2,cost));
			adj[r2].add(new Node(r1,cost));
		}
		bfs();
		System.out.println(answer);

	}//end of main
	private static void bfs() {
		Queue<int[]> queue=new LinkedList<>();
		boolean visit[]=new boolean[N];
		queue.add(new int [] {room1,0,0});
		visit[room1]=true;
		while(!queue.isEmpty()) {
			int cur[]=queue.poll();
			int idx=cur[0];
			int sum=cur[1];
			int max=cur[2];
			if(idx==room2) {
				answer=sum-max;
				return ;
			}
			for (Node node : adj[idx]) {
				if(!visit[node.idx]) {
					visit[node.idx]=true;
					queue.add(new int [] {node.idx,sum+node.cost,Math.max(node.cost, max)});
				}
			}
		}
		
	}


}//end of class 
