

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Solution_1228_암호문1_최수람 {
	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		System.setIn(new FileInputStream("1228_input.txt"));
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int T=10;
		for(int tc=1;tc<=10;tc++) {
			
			int N=Integer.parseInt(br.readLine().trim());
			LinkedList<Integer> numlist=new LinkedList<>();
			
			StringTokenizer st=new StringTokenizer(br.readLine());
			for(int i=0;i<N;i++) {
				numlist.add(Integer.parseInt(st.nextToken()));
			}
			int D=Integer.parseInt(br.readLine().trim());
			StringTokenizer st2=new StringTokenizer(br.readLine(),"I");
			for(int i=0;i<D;i++) {
				String line=st2.nextToken().trim();
				StringTokenizer tmp=new StringTokenizer(line);
				int index=Integer.parseInt(tmp.nextToken());
				int cnt=Integer.parseInt(tmp.nextToken());
				for(int j=0;j<cnt;j++) {
					int num=Integer.parseInt(tmp.nextToken());
					numlist.add(index+j,num);
				}
			}
			System.out.print("#"+tc+" ");
			for(int i=0;i<10;i++)
				System.out.print(numlist.get(i)+" ");
			System.out.println();
		}
	}

}
