
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
//풀이 참조 
//처음 아이디어 : 모든 방향으로 탐색 , 움직인 방향의 갯수를 담는 배열,경로를 담는 arraylist 사용-> 사각형이 되면 정답 갱신 -> 사각형이 아니여도 조건만족 가능 
//수정한 아이디어 : 한 방향으로 가다가 막히면 반시계방향으로 회전 -> 무한루프 
//풀이 : 1차원 visit 배열을 사용하여 겹치지 않는 경로 형성 
//원래 방향 & 반시계 방향으로 회전하여 완전탐색 
public class Solution_2105_디저트카페 {
	static int N,answer,sx,sy;
	static int [][] map;
	static boolean []visit;
	public static void main(String[] args) throws Exception{
		//System.setIn(new FileInputStream("2105_input.txt"));
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int T=Integer.parseInt(br.readLine());
		for(int tc=1;tc<=T;tc++){
			N=Integer.parseInt(br.readLine());
			map=new int [N][N];
			visit=new boolean [101];
			answer=-1;
			for(int i=0;i<N;i++){
				StringTokenizer st=new StringTokenizer(br.readLine()," ");
				for(int j=0;j<N;j++){
					map[i][j]=Integer.parseInt(st.nextToken());
				}
			}
			//출발점 지정 
			for(int i=0;i<N;i++){
				for(int j=1;j<N-1;j++){
					visit[map[i][j]]=true;
					sx=i;
					sy=j;
					dfs(i,j,0,0);
					visit[map[i][j]]=false;
				}
			}
		System.out.println("#"+tc+" "+answer);
		}//end of tc
	}//end of main
	static int dir [][]={{1,1},{1,-1},{-1,-1},{-1,1}};
	private static void dfs(int x, int y, int d,int cnt) {
		// TODO Auto-generated method stub
		if(x==sx&&y==sy&&d==3){
			answer=Math.max(answer, cnt);
			return ;
		}
		boolean turn=true;
		if(x==sx && y==sy) turn=false;
		if(d==3) turn=false;
		int nx,ny;
		for(int i=0;i<=1;i++){
			if(!turn && i==1) continue;
			nx=x+dir[d+i][0];
			ny=y+dir[d+i][1];
			if(0>nx||nx>=N||0>ny||ny>=N) continue;
			if(nx==sx&&ny==sy){
				dfs(nx,ny,d+i,cnt+1);
				break;
			}
			if(!visit[map[nx][ny]]){
				visit[map[nx][ny]]=true;
				dfs(nx,ny,d+i,cnt+1);
				visit[map[nx][ny]]=false;
			}
		}

	}
}//end of class
