


import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.StringTokenizer;
//runtime error 때문에 bfs로 바꿔보기 
public class Solution_1824_혁진이의프로그램검증 {
	static int r,c,dx,dy;
	static char program[][];
	static boolean res;
	static boolean visit[][][][];
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		System.setIn(new FileInputStream("1824_input.txt"));
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int T=Integer.parseInt(br.readLine().trim());
		for(int t=1;t<=T;t++) {
			StringTokenizer st=new StringTokenizer(br.readLine()," ");
			r=Integer.parseInt(st.nextToken());
			c=Integer.parseInt(st.nextToken());
			program=new char [r][c];
			visit=new boolean [r][c][16][4];
			res=false;
			dx=-1;
			dy=-1;
			for(int i=0;i<r;i++) {
				String line=br.readLine();
				for(int j=0;j<c;j++) {
					program[i][j]=line.charAt(j);
					if(program[i][j]=='@'){
						dx=i;
						dy=j;
					}
				}
			}
			if(dx==-1 && dy==-1){
				System.out.println("#"+t+" "+"NO");
				continue;
			}		
		run(0,0,0,1);
			if(res)
				System.out.println("#"+t+" "+"YES");
			else
				System.out.println("#"+t+" "+"NO");
		}//end of tc 
	}//end of main
	// 0: 하  1: 우  2:상  3: 좌
	static int dir[][]= {{1,0},{0,1},{-1,0},{0,-1}};
	private static void run(int x,int y,int m,int d) {
		// TODO Auto-generated method stub
		LinkedList<int []> q=new LinkedList<>();
		q.offer(new int [] {x,y,m,d});
		visit[x][y][m][d]=true;
		boolean qu=false;
		while(!q.isEmpty()){
			qu=false;
			int cur[]=q.poll();
			int cx=cur[0];
			int cy=cur[1];
			int cm=cur[2];
			int cd=cur[3];
			if(program[cx][cy]=='@'){
				res=true;
				break;
			}
			int nx=cx,ny=cy,nd=cd,nm=cm;
			//좌
			if(program[cx][cy]=='<') {
				nd=3;
			}//우
			else if (program[cx][cy]=='>') {
				nd=1;
			}//상 
			else if(program[cx][cy]=='^') {
				nd=2;
			}//하
			else if(program[cx][cy]=='v') {
				nd=0;
			}else if(program[cx][cy]=='_') {
				nd=cm==0? 1:3;
			}else if(program[cx][cy]=='|') {
				nd=cm==0? 0:2;
			}else if(program[cx][cy]=='?') {
				qu=true;
				for(int di=0;di<4;di++) {
					switch(di) {
					case 0: 
						nx=cx+dir[0][0];
						ny=cy+dir[0][1];
						if(nx>=r) {
							nx=0;
						}
						if(!visit[nx][ny][nm][0]){
							visit[nx][ny][nm][0]=true;
							q.offer(new int [] {nx,ny,nm,0});
						}
						break;
					case 1:
						nx=cx+dir[1][0];
						ny=cy+dir[1][1];
						if(ny>=c) {
							ny=0;
						}
						if(!visit[nx][ny][nm][1]){
							visit[nx][ny][nm][1]=true;
							q.offer(new int [] {nx,ny,nm,1});
						}
						break;
					case 2: 
						nx=cx+dir[2][0];
						ny=cy+dir[2][1];
						if(nx<0) {
							nx=r-1;
						}
						if(!visit[nx][ny][nm][2]){
							visit[nx][ny][nm][2]=true;
							q.offer(new int [] {nx,ny,nm,2});
						}
						break;
					case 3:
						nx=cx+dir[3][0];
						ny=cy+dir[3][1];
						if(ny<0) {
							ny=c-1;
						}
						if(!visit[nx][ny][nm][3]){
							visit[nx][ny][nm][3]=true;
							q.offer(new int [] {nx,ny,nm,3});
						}
						break;
					}
				}	
			}else if('0'<=program[cx][cy]&&program[cx][cy]<='9') {
				nm=program[cx][cy]-'0';
			}else if(program[cx][cy]=='+') {
				if(nm ==15) {
					nm=0;
				}
				else 
					nm+=1;
			}
			else if(program[cx][cy]=='-') {
				if(nm ==0) {
					nm=15;
				}
				else 
					nm-=1;
			}
			//범위 벗어나는 경우 처리 
			// 0: 하  1: 우  2:상  3: 좌
			if(!qu) {
				switch(nd) {
				case 0: 
					nx=cx+dir[nd][0];
					ny=cy+dir[nd][1];
					if(nx>=r) {
						nx=0;
					}
					break;
				case 1:
					nx=cx+dir[nd][0];
					ny=cy+dir[nd][1];
					if(ny>=c) {
						ny=0;
					}
					break;
				case 2: 
					nx=cx+dir[nd][0];
					ny=cy+dir[nd][1];
					if(nx<0) {
						nx=r-1;
					}
					break;
				case 3:
					nx=cx+dir[nd][0];
					ny=cy+dir[nd][1];
					if(ny<0) {
						ny=c-1;
					}
					break;
				}
				if(!visit[nx][ny][nm][nd]){
					visit[nx][ny][nm][nd]=true;
					q.offer(new int [] {nx,ny,nm,nd});
				}
			}
		}
	}
}//end of class