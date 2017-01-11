// Hacker Cup 2017
// Qualification Round
// Lazy Loading
// Wesley May

import java.util.*;

public class LazyLoading 
{
	public static void main(String args[])
	{
		Scanner scan = new Scanner(System.in);
		int T = scan.nextInt();

		for(int ca=1;ca <= T;ca++)
		{
			int N = scan.nextInt();
			
			int[] W = new int[N];

			for(int i=0;i < N;i++)
				W[i] = scan.nextInt();

			Arrays.sort(W);
			
			int ans = 0;
			int L = 0;
			int R = N-1;

			while(L <= R)
			{
				int count = 1;
				while(count * W[R] < 50)
					count++;
		
				if(count <= R - L + 1)
					ans++;

				L += count - 1;
				R--;
			}

			System.out.println("Case #" + ca + ": " + ans);
		}
	}
}
