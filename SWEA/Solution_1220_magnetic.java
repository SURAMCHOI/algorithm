

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Solution_1220_magnetic {
	static int N;
	static int answer;
	static int [][]map;
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		System.setIn(new FileInputStream("1220_input.txt"));
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		for(int tc=1;tc<=10;tc++){
			N=Integer.parseInt(br.readLine().trim());
			map=new int [N][N];
			for(int i=0;i<N;i++){
				StringTokenizer st=new StringTokenizer(br.readLine());
				for(int j=0;j<N;j++){
					map[i][j]=Integer.parseInt(st.nextToken());
				}
			}
			for(int i=0;i<N;i++){
				for(int j=0;j<N;j++){
					if(map[j][i]!=0){
						move(j,i,map[j][i]);
					}
				}
			}
			for(int i=0;i<N;i++){
				count(i);
			}
			System.out.println("#"+tc+" "+answer);
			answer=0;
		}
	}

	private static void count(int i) {
		// TODO Auto-generated method stub
		int num=0;
		for(int x=0;x<N;x++){
			if(map[x][i]==1){
				if(num==0)
					num=1;
			}
			else if(map[x][i]==2){
				if(num==1){
					num=0;
					answer++;
				}
			}
		}
	}
	private static void move(int x, int y, int num) {
		// TODO Auto-generated method stub
		if(num==1){
			for(int i=x;i<N;i++){
				if(map[i][y]==2)
					return ;
			}
			map[x][y]=0;
		}
		else if(num==2){
			for(int i=N-1;i>=0;i--){
				if(map[i][y]==1)
					return ;
			}
			map[x][y]=0;
		}
	}

}
