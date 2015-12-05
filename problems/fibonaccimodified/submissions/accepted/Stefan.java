//Author: Stefan Toman

import java.math.BigInteger;
import java.util.Scanner;

public class Stefan {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        BigInteger a = s.nextBigInteger();
        BigInteger b = s.nextBigInteger();
        int n = s.nextInt();
        for(int i = 2; i < n; i++) {
            BigInteger c = b.multiply(b).add(a);
            a = b;
            b = c;
        }
        System.out.println(b);
    }
}
