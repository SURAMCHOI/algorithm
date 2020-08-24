

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

public class Solution_1208_Flatten {
	static int N;
	static int box[];
	static int answer;
	public static void main(String[] args) throws FileNotFoundException {
		// TODO Auto-generated method stub
	//	System.setIn(new FileInputStream("input.txt"));
		Scanner sc=new Scanner(System.in);
		int T=10;
		for(int testcase=1;testcase<=T;testcase++) {
			answer=-1;
			N=sc.nextInt();
			box=new int [100];
			for(int i=0;i<100;i++)
				box[i]=sc.nextInt();
			for(int i=0;i<N;i++) {
				if(answer!=-1&&answer<=0)
					return;
				Arrays.sort(box);
				box[0]+=1;
				box[99]-=1;		
				Arrays.sort(box);
				answer=box[99]-box[0];
			}
			System.out.println("#"+testcase+" "+answer);
		}
	}
}
