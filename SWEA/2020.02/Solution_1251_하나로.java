

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.StringTokenizer;
//각 정점의 최소경로로 n-1번 연결 -> cycle이 생기는 경우를 생각하지 못함 
//크루스칼 알고리즘 적용
//1. 가중치를 중심으로 오름차순으로 정렬
//2. 적은 가중치를 선택 
//3. 선택한 가중치가 이미 연결되어 있는지, 사이클을 형성하는지 검사
//4. 연결되어있지않고, 사이클을 만들지 않으면 연결 
public class Solution_1251_하나로 {
	static double answer;
	static int N;
	static int[] ix,iy,p;
	static double e;
	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		//System.setIn(new FileInputStream("1251_input.txt"));
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int T=Integer.parseInt(br.readLine());
		for(int tc=1;tc<=T;tc++){
			N=Integer.parseInt(br.readLine());
			ix=new int [N];
			iy=new int [N];
			p=new int [N];
			answer=0;
			for(int i=0;i<N;i++){
				p[i]=i;
			}
			StringTokenizer st=new StringTokenizer(br.readLine()," ");
			for(int i=0;i<N;i++){
				ix[i]=Integer.parseInt(st.nextToken());
			}
			st=new StringTokenizer(br.readLine()," ");
			for(int i=0;i<N;i++){
				iy[i]=Integer.parseInt(st.nextToken());
			}
			e=Double.parseDouble(br.readLine());
			solution();
			answer*=e;
			answer=Math.round(answer);
			System.out.print("#"+tc+" ");
			System.out.printf("%.0f\n",answer);
		}
	}//end of main
	private static void solution() {
		// TODO Auto-generated method stub
		//간선 만들기  (가중치, n1,n2)
		ArrayList<double []> v=new ArrayList<>();
		for(int i=0;i<N;i++){
			for(int j=i+1;j<N;j++){
				double dist=caldist(i,j);
				v.add(new double [] {dist,i,j});
			}
		}
		//정렬
		Collections.sort(v,new Comparator<double []>() {

			@Override
			public int compare(double[] o1, double[] o2) {
				// TODO Auto-generated method stub
				return (int) (o1[0]-o2[0]);
			}
		});
		//작은 가중치부터 선택, cycle을 만드는지, 이미 연결되어 있는지 검사 -> 아니면 연결 
		for(int i=0;i<v.size();i++){
			double cost=v.get(i)[0];
			int n1=(int)v.get(i)[1];
			int  n2=(int)v.get(i)[2]; 
			if(findParent(n1)!=findParent(n2)){
				union(n1,n2);
				answer+=cost;
			}
		}
		
	}
	private static void union(int n1, int n2) {
		// TODO Auto-generated method stub
		int p1=findParent(n1);
		int p2=findParent(n2);
		if(p1!=p2)
			p[p2]=p1;
	}
	private static int findParent(int n1) {
		// TODO Auto-generated method stub
		if(p[n1]==n1)
			return n1;
		return p[n1]=findParent(p[n1]);
	}
	private static double caldist(int i, int j) {
		// TODO Auto-generated method stub
		double res=0;
		double dx=ix[i]-ix[j];
		double dy=iy[i]-iy[j];
		res=Math.pow(dx, 2)+Math.pow(dy, 2);
		return res;
	}
}//end of class
