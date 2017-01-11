// Hacker Cup 2017
// Qualification Round
// Lazy Loading
// Progress Pie

import java.util.*;

public class ProgressPie 
{
	public static void main(String args[])
	{
		double EPS = 0.000001;
		Scanner scan = new Scanner(System.in);
		int T = scan.nextInt();

		for(int ca=1;ca <= T;ca++)
		{
			double p = scan.nextDouble() / 100;
			double x = scan.nextDouble();
			double y = scan.nextDouble();
			boolean ans = solve(p, x, y);

			System.out.println("Case #" + ca + ": " + (ans ? "black" : "white"));
		}
	}

	public static boolean solve(double p, double x, double y)
	{
		if(p == 0) return false;

		double dx = x - 50;
		double dy = y - 50;
		double d = Math.sqrt(dx*dx + dy*dy);
		if (d > 50) return false;

		if(dx == 0 && dy == 0) return true;

		double theta = Math.atan2(dy, dx);
		if (theta < 0) theta += 2 * Math.PI;
		double myp = (2 * Math.PI - theta) / (2 * Math.PI);
		myp += 0.25;
		if (myp >= 1) myp -= 1;

		return myp <= p;
	}
}
