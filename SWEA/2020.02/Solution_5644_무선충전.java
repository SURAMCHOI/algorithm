

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class BC {
	int x;
	int y;
	int c;
	int p;
	public BC(int x, int y, int c, int p) {
		this.x = x;
		this.y = y;
		this.c = c;
		this.p = p;
	}
}
public class Solution_5644_무선충전 {
    static int M,A,answer,sum; // 총 이동 시간  : M, BC 개수 : A
	static int[] u1,u2;
	static BC bc[];
	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		//System.setIn(new FileInputStream("5644_input.txt"));
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int T=Integer.parseInt(br.readLine());
		for(int tc=1;tc<=T;tc++){
			StringTokenizer st=new StringTokenizer(br.readLine()," ");
			M=Integer.parseInt(st.nextToken());
			A=Integer.parseInt(st.nextToken());
			u1=new int [M+1];
			u2=new int [M+1];
			answer=0;
			bc=new BC [A];
			st=new StringTokenizer(br.readLine()," ");
			for(int i=1;i<=M;i++){
				u1[i]=Integer.parseInt(st.nextToken());
			}
			st=new StringTokenizer(br.readLine()," ");
			for(int i=1;i<=M;i++){
				u2[i]=Integer.parseInt(st.nextToken());
			}
			for(int i=0;i<A;i++){
				st=new StringTokenizer(br.readLine()," ");
				int x=Integer.parseInt(st.nextToken());
				int y=Integer.parseInt(st.nextToken());
				int c=Integer.parseInt(st.nextToken());
				int p=Integer.parseInt(st.nextToken());
				bc[i]=new BC(y,x,c,p);
			}
			move();
			System.out.println("#"+tc+" "+answer);
		}//end of tc
	}//end of main
	//0 : 이동x 1 : 상  2 : 우  3 : 하  4 : 좌 
	static int dir [][]={{0,0},{-1,0},{0,1},{1,0},{0,-1}};
	private static void move() {
		int u1x=1,u1y=1,u2x=10,u2y=10;
		for(int i=0;i<=M;i++){
			u1x+=dir[u1[i]][0];
			u1y+=dir[u1[i]][1];
			u2x+=dir[u2[i]][0];
			u2y+=dir[u2[i]][1];
			check(u1x,u1y,u2x,u2y);
		}
		return ;
	}
	private static void check(int u1x, int u1y, int u2x, int u2y) {
		boolean b1[]= new boolean [A];
		boolean b2[]=new boolean [A];
		//몇개의 bc에 속하는지
		for(int i=0;i<A;i++){
			int x=bc[i].x;
			int y=bc[i].y;
			int c=bc[i].c;
			int d1=Math.abs(x-u1x)+Math.abs(y-u1y);
			int d2=Math.abs(x-u2x)+Math.abs(y-u2y);
			if(d1<=c)
				b1[i]=true;
			if(d2<=c)
				b2[i]=true;
		}
		int sum=0;
		for(int i=0;i<A;i++){
			for(int j=0;j<A;j++){
				int p1=bc[i].p;
				int p2=bc[j].p;
				if(i==j){
					if(b1[i]&&b2[j]){
						p1/=2;
						p2/=2;
					}
				}
				if(!b1[i])
					p1=0;
				if(!b2[j])
					p2=0;
				sum=Math.max(sum, p1+p2);
			}
		}
		
		answer+=sum;
	}
}//end of class
