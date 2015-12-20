//Author: Stefan Toman
//This submission still solves the small and medium inputs.

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.math.BigInteger;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int t = Integer.parseInt(r.readLine());
        for (int i = 0; i < t; i++) {
            BigInteger a = new BigInteger(r.readLine(), 7);
            BigInteger b = new BigInteger(r.readLine(), 7);
            int l = Integer.parseInt(r.readLine());
            BigInteger m = new BigInteger("7").pow(l);
            sb.append(a.divide(b).mod(m).toString(7));
            sb.append("\n");
        }
        System.out.print(sb);
    }
}
