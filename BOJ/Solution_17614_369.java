

import java.util.Scanner;

public class Solution_17614_369 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		int N=sc.nextInt();
		int clap=0;
		int index=0;
		int tmp=0;
		for(int i=1;i<=N;i++){
			index=i;
			while(index>0){
				tmp=index%10;
				if(tmp==3){
					clap++;
				}else if(tmp==6){
					clap++;
				}else if(tmp==9){
					clap++;
				}
				index/=10;
			}
		}
		System.out.println(clap);
	}
}
