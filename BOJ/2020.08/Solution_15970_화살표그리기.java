package backjoon;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Solution_15970_화살표그리기 {
	static class Point implements Comparable<Point>{
		int pos;
		int col;
		@Override
		public int compareTo(Point o) {
			return Integer.compare(this.pos, o.pos);
		}
		public Point(int pos,int col) {
			this.pos=pos;
			this.col=col;
		}
	}
	public static void main(String[] args) throws Exception{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int N=Integer.parseInt(br.readLine());
		int answer=0;
		Point[] points=new Point[N];
		StringTokenizer st=null;
		for(int i=0;i<N;i++) {
			st=new StringTokenizer(br.readLine()," ");
			int pos=Integer.parseInt(st.nextToken());
			int col=Integer.parseInt(st.nextToken());
			points[i]=new Point(pos,col);
		}
		Arrays.sort(points);
		for(int i=0;i<N;i++) {
			int min=Integer.MAX_VALUE;
			for(int j=0;j<N;j++) {
				if(i==j) continue;
				if(points[i].col==points[j].col) {
					min=Math.min(min, Math.abs(points[i].pos-points[j].pos));
				}
			}
			answer+=min;
		}
		System.out.println(answer);
	}//end of main
}//end of class 
