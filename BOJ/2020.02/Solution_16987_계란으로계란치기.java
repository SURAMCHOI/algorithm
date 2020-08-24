

import java.util.Scanner;
class Egg{
	int s;
	int w;
	boolean broken=false;
}
public class Solution_16987_계란으로계란치기{
	static int N;
	static Egg [] e;
	static int answer;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		N=sc.nextInt();
		e=new Egg [N];
		answer=0;
		for(int i=0;i<N;i++)
		{
			e[i]=new Egg();
			e[i].s=sc.nextInt();
			e[i].w=sc.nextInt();
		}
		dfs(0);
		System.out.println(answer);
	}
	private static void dfs(int hand) {
		// TODO Auto-generated method stub
		//���� �����ʿ� �ִ� ������� �������
		if(hand>=N){
			int cnt=0;
			for(int i=0;i<N;i++){
				if(e[i].broken)
					cnt++;
			}
			answer=Math.max(answer, cnt);
			return ;
		}
		if(e[hand].broken)
			dfs(hand+1);
		boolean allbroken=true;
		for(int i=0;i<N;i++){
			if(i==hand) continue;
			if(e[hand].broken) continue;
			if(!e[i].broken){
				allbroken=false;
				clash(i,hand);
				dfs(hand+1);
				copy(i,hand);
			}
		}
		if(allbroken)
			dfs(hand+1);
	}
	private static void copy(int i, int hand) {
		// TODO Auto-generated method stub
		e[hand].s+=e[i].w;
		e[i].s+=e[hand].w;
		if(e[hand].s<=0)
			e[hand].broken=true;
		else
			e[hand].broken=false;
		if(e[i].s<=0)
			e[i].broken=true;
		else
			e[i].broken=false;
		
	}
	private static void clash(int i, int hand) {
		// TODO Auto-generated method stub
		e[hand].s-=e[i].w;
		e[i].s-=e[hand].w;
		if(e[hand].s<=0)
			e[hand].broken=true;
		if(e[i].s<=0)
			e[i].broken=true;
	}

}
