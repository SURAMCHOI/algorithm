
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Solution_5658_보물상자비밀번호 {
	static int N,K,size;
	static double answer;
	static ArrayList<Double> list;
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		//System.setIn(new FileInputStream("5658_input.txt"));
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int T=Integer.parseInt(br.readLine());
		for(int tc=1;tc<=T;tc++){
			StringTokenizer st=new StringTokenizer(br.readLine()," ");
			N=Integer.parseInt(st.nextToken());
			K=Integer.parseInt(st.nextToken());
			size=N/4;
			list=new ArrayList<>();
			String nums=br.readLine();
			rotate(0,nums);
			System.out.print("#"+tc+" ");
			System.out.printf("%.0f\n",answer);
		}
	}//end of main
	private static void rotate(int cnt, String nums) {
		// TODO Auto-generated method stub
		if(cnt==size){
			Collections.sort(list,new Comparator<Double>() {
				@Override
				public int compare(Double o1, Double o2) {
					// TODO Auto-generated method stub
					return (int)(o2-o1);
				}
			});
			answer=list.get(K-1);
			return ;
		}
		for(int i=0;i+size<=N;i+=size){
			double num=cal(nums.substring(i,i+size));
			if(!list.contains(num))
				list.add(num);
		}
		String nstr=nums.substring(0,N-1);
		char echr=nums.charAt(N-1);
		rotate(cnt+1, echr+nstr);
	}
	private static double cal(String str) {
		// TODO Auto-generated method stub
		int len=str.length();
		double num=0;
		for(int i=0;i<len;i++){
			char c=str.charAt(i);
			int tmp=0;
			if('0'<=c && c<='9'){
				tmp=c-'0';
			}
			else if('A'<=c&&c<='F'){
				tmp=c-'7';
			}
			num+=tmp * Math.pow(16, len-(i+1));
		}
		return num;
	}
}//end of class
