
import java.util.Scanner;

public class Solution_8958_OX퀴즈 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		int T=sc.nextInt();
		for(int t=1;t<=T;t++){
			String line=sc.next();
			int len=line.length();
			int score[]=new int [len];
			int num=1;
			for(int i=0;i<len;i++){
				if(line.charAt(i)=='O'){
					score[i]=num;
					num++;
				}
				else{
					num=1;
				}
			}
			
			int sum=0;
			for(int i=0;i<len;i++){
				sum+=score[i];
			}
			System.out.println(sum);
		}
	}

}
