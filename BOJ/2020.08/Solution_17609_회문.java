package backjoon;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Solution_17609_회문 {
	static boolean isP;
	public static void main(String[] args) throws Exception{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int T=Integer.parseInt(br.readLine());
		for(int t=1;t<=T;t++) {
			String str=br.readLine();
			StringBuilder sb= new StringBuilder();
			sb=sb.append(str);
			//ȸ�� : 0 ����ȸ�� :1 �Ѵ� �ƴϸ� :2 
			if(str.equals(sb.reverse().toString())) {
				System.out.println(0);
			}else {
				//����ȸ������ �˻��ϱ� 
				int len=str.length();
				isP=false;
				checkPseudo(false,0,len-1,str);
				System.out.println(isP==true? 1:2);
			}
		}
	}//end of main

	private static void checkPseudo(boolean erase,int left,int right,String str) {
		if(left>=right) {
			isP=true;
			return;
		}
		if(str.charAt(left)!=str.charAt(right)) {
			if(erase) {
				return;
			}
			//left skip
			if(str.charAt(left+1)==str.charAt(right)) {
				checkPseudo(true,left+1,right,str);
			}if(str.charAt(left)==str.charAt(right-1)){
			//right skip
				checkPseudo(true,left, right-1, str);
			}else {
				return;
			}
		}else {
			checkPseudo(erase,left+1, right-1, str);
		}
	}
}//end of class 
