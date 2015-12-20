//Author: Stefan Toman
//generate random inputs

import java.math.BigInteger;
import java.util.Random;

public class RanmdomGenerator {

	public static void main(String[] args) {
		Random r = new Random(0);
		int t = 100;
		System.out.println(t);
		for (int i = 0; i < t; i++) {
			BigInteger b = BigInteger.ZERO;
			BigInteger c = BigInteger.ZERO;
			for (int j = 0; j < 1000; j++) {
				b = b.multiply(BigInteger.TEN).add(BigInteger.valueOf(r.nextInt(10)));
				c = c.multiply(BigInteger.TEN).add(BigInteger.valueOf(r.nextInt(10)));
			}
			System.out.println(b.multiply(c).toString(7));
			System.out.println(b.toString(7));
			System.out.println(1000);
		}
	}

}
