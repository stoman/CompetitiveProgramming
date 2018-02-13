//Author: Stefan Toman

import java.io.*;
import java.util.*;

public class Stefan {

    static void solve(int[] arr, int money) {
        HashMap<Integer, Integer> hs = new HashMap<Integer, Integer>();
        for(int i = 0; i < arr.length; i++) {
            if(hs.containsKey(arr[i])) {
                System.out.format("%d %d\n", hs.get(arr[i]) + 1, i + 1);
                return;
            }
            hs.put(money - arr[i], i);
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for(int a0 = 0; a0 < t; a0++){
            int money = in.nextInt();
            int n = in.nextInt();
            int[] arr = new int[n];
            for(int arr_i = 0; arr_i < n; arr_i++){
                arr[arr_i] = in.nextInt();
            }
            solve(arr, money);
        }
        in.close();
    }
}
