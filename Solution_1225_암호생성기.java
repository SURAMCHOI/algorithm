package d3;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Solution_1225_암호생성기 {

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		System.setIn(new FileInputStream("1225_input.txt"));
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		for(int tc=1;tc<=10;tc++) {
			LinkedList<Integer> queue=new LinkedList<>();
			br.readLine();
			StringTokenizer st=new StringTokenizer(br.readLine()," "); //공백을 기준으로 문자열을 자름 
			for(int i=0;i<8;i++) {
				queue.offer(Integer.parseInt(st.nextToken()));
			}
			int minus=1;
			while(true) {
				int num=queue.poll();
				num-=minus;
				minus+=1;
				if(minus%5==0)
					minus=5;
				else
					minus=minus%5;
				if(num<=0)
				{
					queue.offer(0);
					break;
				}
				queue.offer(num);
			}
			System.out.print("#"+tc+" ");
			for(int i=0;i<8;i++) {
				System.out.print(queue.poll()+" ");
			}
			System.out.println();
		}
	}

}
