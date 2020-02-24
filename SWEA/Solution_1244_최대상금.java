
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;
//1244 최대 상금 
public class Solution_1244_최대상금 {
	static int c;
	static boolean check[][];
	static int size;
	static int answer;
	public static void main(String[] args) throws FileNotFoundException {
		// TODO Auto-generated method stub
		System.setIn(new FileInputStream("input.txt"));
		Scanner sc=new Scanner(System.in);
		int T=sc.nextInt();
		for(int testcase=1;testcase<=T;testcase++) {
			String nums=sc.next();
			size=nums.length();
			c=sc.nextInt();
			check=new boolean[c][1000000];
			dfs(nums.toCharArray(),0);
			System.out.println("#"+testcase+" "+answer);
			answer=0;
		}
		
	}
	private static void dfs(char[] nums, int cnt) {
		// TODO Auto-generated method stub
		if(cnt==c) {
			answer=Math.max(makeNum(nums),answer);
			return ;
		}
		for(int i=0;i<size-1;i++) {
			for(int j=i+1;j<size;j++) {
					char[] tmp=swap(nums,i,j);
					int num=makeNum(tmp);
					if(!check[cnt][num]) {
						check[cnt][num]=true;
						dfs(tmp,cnt+1);
					}
			}
		}	
	}
	private static int makeNum(char[] nums) {
		// TODO Auto-generated method stub
		return Integer.valueOf(String.valueOf(nums));
	}
	private static char[] swap(char[] nums, int index1, int index2) {
		// TODO Auto-generated method stub
        char tmp[]=nums.clone();
        char num=tmp[index1];
        tmp[index1]=tmp[index2];
        tmp[index2]=num;
        return tmp;
        
	}
}
