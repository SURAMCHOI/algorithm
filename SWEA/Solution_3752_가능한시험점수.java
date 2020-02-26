

import java.util.Arrays;
import java.util.Scanner;

public class Solution_3752_가능한시험점수{
	static int scores[];
	static boolean check[];
	static int N;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		int T=sc.nextInt();
		for(int testcase=1;testcase<=T;testcase++){
			N=sc.nextInt();
			scores=new int [N];
			int max=0;
			int answer=0;
			for(int i=0;i<N;i++){
				scores[i]=sc.nextInt();
				max+=scores[i];
			}
			check=new boolean [max+1];
			check[0]=true;
			for(int i=0;i<N;i++){
				int num=scores[i];
				for(int j=max;j>=0;j--){
					if(check[j]){
						check[j+num]=true;						
					}
				}
			}
			for(int i=0;i<max+1;i++){
				if(check[i]){
					answer++;
				}
			}
			System.out.println("#"+testcase+" "+answer);
		}
	}

}
