

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution_7272_안경이없어 {
	static String s1,s2;
	static String same[]={"CEFGHIJKLMNSTUVWXYZ","ADOPQR","B"};
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int T=Integer.parseInt(br.readLine());
		for(int tc=1;tc<=T;tc++){
			StringTokenizer st=new StringTokenizer(br.readLine()," ");
			s1=st.nextToken();
			s2=st.nextToken();
			boolean res=isSame();
			if(res)
				System.out.println("#"+tc+" "+"SAME");
			else
				System.out.println("#"+tc+" "+"DIFF");
		}
	}
	private static boolean isSame() {
		//문자열의 길이가 다를때
		if(s1.length()!=s2.length())
			return false;
		int size=s1.length();
		boolean res=true;
		for(int i=0;i<size;i++){
			for(int j=0;j<same.length;j++){
				if(same[j].contains(s1.substring(i, i+1)) && same[j].contains(s2.substring(i, i+1)))
					continue;
				else if(!same[j].contains(s1.substring(i, i+1)) && !same[j].contains(s2.substring(i, i+1)))
					continue;
				else{
					res=false;
					break;
				}
			}
			if(!res)
				break;
		}			
		return res;
	}

}
