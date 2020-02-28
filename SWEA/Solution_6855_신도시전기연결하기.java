

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;
import java.util.StringTokenizer;
//nCk 로 전선 길이의 최솟값을 갱신 --> 시간초과 
//k 등분으로 나누고 , 그 가운데 인덱스에 발전소 설치 -> 전선 길이 계산 -> 런타임 에러 
/*
 * (1) 전선 길이 구하기
 * (2) 전선 길이 정렬
 * (3) 작은 전선부터 선택 (N-K개) 
 */
public class Solution_6855_신도시전기연결하기 {
	static int N,K,answer;
	static int [] loc,dist;
	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		//System.setIn(new FileInputStream("6855_input.txt"));
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int T=Integer.parseInt(br.readLine());
		for(int tc=1;tc<=T;tc++){
			StringTokenizer st=new StringTokenizer(br.readLine()," ");
			N=Integer.parseInt(st.nextToken());
			K=Integer.parseInt(st.nextToken());
			loc=new int [N];
			dist=new int [N-1];
			answer=0;
			st=new StringTokenizer(br.readLine()," ");
			for(int i=0;i<N;i++){
				loc[i]=Integer.parseInt(st.nextToken());
			}
			for(int i=0;i<N-1;i++){
				dist[i]=loc[i+1]-loc[i];
			}
			Arrays.sort(dist);
			for(int i=0;i<N-K;i++){
				answer+=dist[i];
			}
			System.out.println("#"+tc+" "+answer);
		}
	}//end of main
}//end of class
