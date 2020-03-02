
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;
class Desk{
	int pt;
	int cur;
	public Desk(int pt) {
		this.pt = pt;
		this.cur=0;
	}
}
public class Solution_2477_차량정비소 {
	static int N,M,K,A,B,answer;
	static Desk[] rec,rep;
	static int clist[][]; // 0: 도착시간  1: 접수 창구 번호  2: 정비 창구 번호  
	public static void main(String[] args) throws Exception{
		//System.setIn(new FileInputStream("2477_input.txt"));
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int T=Integer.parseInt(br.readLine());
		for(int tc=1;tc<=T;tc++){
			StringTokenizer st=new StringTokenizer(br.readLine()," ");
			N=Integer.parseInt(st.nextToken());		
			rec=new Desk [N+1];
			M=Integer.parseInt(st.nextToken());
			rep=new Desk [M+1];
			K=Integer.parseInt(st.nextToken());
			clist=new int [K+1][3];
			A=Integer.parseInt(st.nextToken());
			B=Integer.parseInt(st.nextToken());
			answer=0;
			st=new StringTokenizer(br.readLine()," ");
			for(int i=1;i<=N;i++){
				int t=Integer.parseInt(st.nextToken());
				rec[i]=new Desk(t);
			}
			st=new StringTokenizer(br.readLine()," ");
			for(int i=1;i<=M;i++){
				int t=Integer.parseInt(st.nextToken());
				rep[i]=new Desk(t);
			}
			st=new StringTokenizer(br.readLine()," ");
			for(int i=1;i<=K;i++){
				clist[i][0]=Integer.parseInt(st.nextToken());
			}
			Arrays.sort(clist, new Comparator<int []>() {
				@Override
				public int compare(int[] o1, int[] o2) {
					// TODO Auto-generated method stub
					return o1[0]-o2[0];
				}
			});
			solution();
			if(answer==0)
				answer=-1;
			System.out.println("#"+tc+" "+answer);
		}
	}//end of main
	private static void solution() {
		// TODO Auto-generated method stub
		PriorityQueue<Integer> waiting_rec=new PriorityQueue<>();// 접수창구를 기다리는 고객 
		PriorityQueue<int []> end_rec=new PriorityQueue<>(new Comparator<int []>() {
			@Override
			public int compare(int [] o1, int [] o2) {
				// TODO Auto-generated method stub
				return o1[1]-o2[1];
			}
		}); // 접수 창구처리가 끝난 고객 
		Queue <Integer> waiting_rep=new LinkedList<>();	//정비창구를 기다리는 고객
		Queue<Integer> cus=new LinkedList<>();//도착한 고객들 
		int time=clist[1][0];
		int index=1;//처리할 고객 시작 번호
		boolean con=true;
		while(con){
			int rec_cur=0;
			if(!con){
				break;
			}
			for(int i=index;i<=K;i++){
				if(time==clist[i][0]){
					cus.offer(i);
					index=i+1;
				}
				if(time<clist[i][0])
					break;
			}
			//비울 수 있는 접수창구 비우기 
			for(int i=1;i<=N;i++){
				if(rec[i].cur==0) continue;
				int cnum=rec[i].cur;
				if(time==rec[i].pt+clist[cnum][0]){
					end_rec.offer(new int [] {cnum,i});
					if(!waiting_rec.isEmpty()){
						int wnum=waiting_rec.poll();
						clist[wnum][0]=time;
						clist[wnum][1]=i;
						rec[i].cur=wnum;						
					}
					else {
						rec[i].cur=0;
					}
				}
			}
			//빈 접수창구에 넣기 
			while(!cus.isEmpty()){
				boolean recfull=true;
				int cur=cus.poll();
				//넣기 
				for(int i=1;i<=N;i++){
					if(rec[i].cur==0){
						clist[cur][0]=time;
						clist[cur][1]=i;
						rec[i].cur=cur;
						recfull=false;
						break;
					}
				}
				//접수 창구가 다 찼으면
				if(recfull){
					waiting_rec.offer(cur);
				}
			}
			//비울 수 있는 정비창구 비우기 
			for(int i=1;i<=M;i++){
				if(rep[i].cur==0) continue;
				int cnum=rep[i].cur;
				if(time==rep[i].pt+clist[cnum][0]){
					if(!waiting_rep.isEmpty()){
						int wnum=waiting_rep.poll();
						clist[wnum][0]=time;
						clist[wnum][2]=i;
						if(i==B&&clist[wnum][1]==A){
							answer+=wnum;
						}
						rep[i].cur=wnum;						
					}
					else {
						rep[i].cur=0;
					}
				}
			}
			//빈 정비창구에 넣기
			while(!end_rec.isEmpty()){
				int cur[]=end_rec.poll();
				boolean repfull=true;
				for(int i=1;i<=M;i++){
					if(rep[i].cur==0){
						clist[cur[0]][0]=time;
						clist[cur[0]][2]=i;
						if(i==B&&cur[1]==A){
							answer+=cur[0];
						}
						rep[i].cur=cur[0];
						repfull=false;
						break;
					}
				}
				//접수 창구가 다 찼으면
				if(repfull){
					waiting_rep.offer(cur[0]);
				}
			}
			for(int i=1;i<=N;i++){
				if(rec[i].cur!=0)
					rec_cur++;
			}
			if(index>K && waiting_rec.isEmpty() && waiting_rep.isEmpty()&&rec_cur==0)
				con=false;
			time++;
			
		}
	}
}// end of class
