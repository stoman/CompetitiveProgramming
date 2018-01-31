//Author: Stefan Toman

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Stefan {
    
    private static long countPossibilities(int[] coins, int n) {
        long[] dp = new long[n + 1];
        dp[0] = 1;
        for(int coin: coins) {
            for(int i = coin; i < dp.length; i++) {
                dp[i] += dp[i - coin];
            }
        }
        return dp[n];
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();
        int coins[] = new int[m];
        for(int coins_i=0; coins_i < m; coins_i++){
            coins[coins_i] = in.nextInt();
        }
        System.out.println(countPossibilities(coins, n));
    }
}
