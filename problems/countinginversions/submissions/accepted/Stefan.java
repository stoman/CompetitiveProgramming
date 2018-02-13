//Author: Stefan Toman

import java.io.*;
import java.util.*;

public class Stefan {

    static long countInversions(int[] a, int b, int e) {
        if(e - b < 1) return 0;
        long ret = countInversions(a, b, (b + e) / 2) + countInversions(a, (b + e) / 2 + 1, e);
        int[] a1 = Arrays.copyOfRange(a, b, (b + e) / 2 + 1);
        int[] a2 = Arrays.copyOfRange(a, (b + e) / 2 + 1, e + 1);
        int i = b;
        int i1 = 0;
        int i2 = 0;
        while(i1 < a1.length && i2 < a2.length) {
            if(a1[i1] <= a2[i2]) {
                a[i] = a1[i1];
                i++;
                i1++;
            }
            else {
                a[i] = a2[i2];
                ret += a1.length - i1;
                i++;
                i2++;
            }
        }
        while(i1 < a1.length) {
            a[i] = a1[i1];
            i++;
            i1++;
        }
        while(i2 < a2.length) {
            a[i] = a2[i2];
            i++;
            i2++;
        }
        return ret;
    }
    
    static long countInversions(int[] a) {
        return countInversions(a, 0, a.length - 1);
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for(int a0 = 0; a0 < t; a0++){
            int n = in.nextInt();
            int[] arr = new int[n];
            for(int arr_i = 0; arr_i < n; arr_i++){
                arr[arr_i] = in.nextInt();
            }
            long result = countInversions(arr);
            System.out.println(result);
        }
        in.close();
    }
}
