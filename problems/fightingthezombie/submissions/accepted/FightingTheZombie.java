// Hacker Cup 2017
// Qualification Round
// Fighting The Zombie
// Wesley May

import java.util.*;

public class FightingTheZombie 
{
	static int H;

	public static void main(String args[])
	{
		double EPS = 0.000001;
		Scanner scan = new Scanner(System.in);
		int T = scan.nextInt();

		for(int ca=1;ca <= T;ca++)
		{
			H = scan.nextInt();
			int S = scan.nextInt();
			Spell[] a = new Spell[S];

			for(int i=0;i < S;i++)
			{
				String str = scan.next();
				int X, Y, Z;

				int didx = str.indexOf("d");
				int plusidx = str.indexOf("+");
				int minusidx = str.indexOf("-");

				X = Integer.parseInt(str.substring(0, didx));

				if(plusidx >= 0)
				{
					Y = Integer.parseInt(str.substring(didx+1, plusidx));
					Z = Integer.parseInt(str.substring(plusidx));
				} 
				else if(minusidx >= 0)
				{
					Y = Integer.parseInt(str.substring(didx+1,minusidx));
					Z = Integer.parseInt(str.substring(minusidx));
				}
				else
				{
					Y = Integer.parseInt(str.substring(didx+1));
					Z = 0;
				}

				a[i] = new Spell(X, Y, Z);
			}

			Arrays.sort(a);

			System.out.printf("Case #%d: %.6f\n", ca, a[0].p);
		}
	}

	static class Spell implements Comparable<Spell>
	{
		int x, y, z;
		public double p;
		double[][] dp;

		public Spell(int ix, int iy, int iz)
		{
			x = ix;
			y = iy;
			z = iz;
			int newH = H - z;

			if(newH <= 0)
			{
				p = 1;
				return;
			}

			dp = new double[newH+1][x+1];
			for(int i=0;i < dp.length;i++)
				Arrays.fill(dp[i], -1);

			p = f(newH, x);
		}

		private double f(int h, int d)
		{
			if(h <= 0) return 1;
			if(d == 0) return 0;
			if(dp[h][d] >= 0) return dp[h][d];

			double ans = 0;
			for(int i=1;i <= y;i++)
			{
				ans += (1.0 / y) * f(h-i, d-1);
			}

			return dp[h][d] = ans;
		}

		public int compareTo(Spell that) {
			if(this.p > that.p) return -1;
			if(this.p < that.p) return 1;
			return 0;
		}
	}
}
