
import java.util.Arrays;
import java.util.Scanner;

public class Solution_1206_view {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
        Scanner sc=new Scanner(System.in);
        int T=10;
        int N,start,end,max;
        int nums[];
        long answer=0;
        for(int testcase=1;testcase<=T;testcase++) {
        	N=sc.nextInt();
        	nums=new int [N];
        	for(int i=0;i<N;i++) {
        		nums[i]=sc.nextInt();
        	}
        	for(int i=2;i<N-2;i++) {
        	    if(nums[i]==0)
        	    	continue;
        		start=i-2;
        	    end=i+2;
        	    max=-1;
        	    for(int j=start;j<=end;j++) {
        	    	if(i==j)
        	    		continue;
        	    	max=Math.max(nums[j],max);
        	    }
        	    if(max>=nums[i])
        	    	continue;
        		answer=(nums[i]-max)+answer;
        	}
        	System.out.println("#"+testcase+" "+answer);
        	answer=0;
        }
	}
}
