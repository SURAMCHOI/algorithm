

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Solution_1215_회문{
	static int L;
	static char [][] map;
	static int answer;
	public static void main(String[] args) throws FileNotFoundException {
		// TODO Auto-generated method stub
		System.setIn(new FileInputStream("input.txt"));
		Scanner sc=new Scanner(System.in);
		for(int testcase=1;testcase<=10;testcase++){
			L=sc.nextInt();
			map=new char [8][8];
			for(int i=0;i<8;i++){
				String str=sc.next();
				map[i]=str.toCharArray();
			}
			for(int i=0;i<8;i++){
				for(int j=0;j<8;j++){
					if(rCheck(i,j))
						answer++;
					if(cCheck(i,j))
						answer++;
				}
			}
			System.out.println("#"+testcase+" "+answer);
			answer=0;
		}
	}
	private static boolean cCheck(int x, int y) {
		// TODO Auto-generated method stub
		boolean res=false;
		if(x+(L-1)>=8) 
			return res;
		String str ="";
		for(int i=0;i<L;i++){
			str+=Character.toString(map[x+i][y]);
		}
		StringBuilder sb=new StringBuilder(str);
		sb.reverse();
		if(str.equals(sb.toString())){
			res=true;
		}
		return res;
	}
	//x,y�� �������� �־��� ���̸�ŭ�� ���� ȸ�� �˻� 
	private static boolean rCheck(int x, int y) {
		// TODO Auto-generated method stub
		boolean res=false;
		if(y+(L-1)>=8) 
			return res;
		String str="";
		for(int i=0;i<L;i++){
			str+=Character.toString(map[x][y+i]);
		}
		StringBuilder sb=new StringBuilder(str);
		sb.reverse();
		if(str.equals(sb.toString())){
			res=true;
		}
		return res;
	}

  }
