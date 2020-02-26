

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Solution_4013_특이한자석 {
	static int K,answer;
	static int m[][];
	static boolean t[];
	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		System.setIn(new FileInputStream("4013_input.txt"));
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int T=Integer.parseInt(br.readLine());
		for(int tc=1;tc<=T;tc++){
			K=Integer.parseInt(br.readLine());
			m=new int [5][8];
			t=new boolean[5];
			answer=0;
			for(int i=1;i<=4;i++){
				StringTokenizer st=new StringTokenizer(br.readLine()," ");
				for(int j=0;j<8;j++){
					m[i][j]=Integer.parseInt(st.nextToken());
				}
			}
			for(int i=0;i<K;i++){
				StringTokenizer st=new StringTokenizer(br.readLine()," ");
				int num=Integer.parseInt(st.nextToken());
				int dir=Integer.parseInt(st.nextToken());
				t[num]=true;
				turn(num,dir);
				Arrays.fill(t, false);
//				for (int[] arr :m) {
//					System.out.println(Arrays.toString(arr));
//				}
			}
			for(int i=1;i<=4;i++){
				answer+=m[i][0]*Math.pow(2, (i-1));
			}
			System.out.println("#"+tc+" "+answer);
		}//end of tc
	}//end of main
	private static void turn(int cur, int dir) {
		// TODO Auto-generated method stub
		int left=cur-1;
		int right=cur+1;
		//왼쪽 자석이 존재한다면 
		if(1<=left && !t[left]){
			if(m[cur][6]!=m[left][2]){
				t[left]=true;
				turn(left,dir*(-1));
			}
		}
		//오른쪽자석이 존재한다면 
		if(right<=4 && !t[right]){
			if(m[cur][2]!=m[right][6]){
				t[right]=true;
				turn(right,dir*(-1));
			}
		}
		//회전
		int tmp []=new int [8];
		tmp=Arrays.copyOf(m[cur],tmp.length);
		switch(dir){
		//시계방향 
		case 1:
			for(int i=0;i<=6;i++){
				m[cur][i+1]=tmp[i];
			}
			m[cur][0]=tmp[7];
			break;
		//반시계 방향 
		case -1:
			for(int i=7;i>0;i--)
				m[cur][i-1]=tmp[i];
			m[cur][7]=tmp[0];
			break;			
		}
	}
}//end of class 
