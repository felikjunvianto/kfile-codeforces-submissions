//tambahkan "Codeforces" di depan filename sebelum di-compile

import java.util.Scanner;

public class Codeforces116A
{
	public static void main(String[] args)
	{
		int x,temp,ans,a,b,N;
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		temp=ans=0;
		for(x=0;x<N;x++)
		{
			a=sc.nextInt();b=sc.nextInt();
			temp+=(b-a);
			if(temp>ans) ans=temp;
		}
		
		System.out.println(ans);
	}
}