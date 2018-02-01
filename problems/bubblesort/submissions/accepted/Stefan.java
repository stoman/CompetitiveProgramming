//Author: Stefan Toman

import java.io.*;
import java.util.*;

public class Stefan {

    public static int[] readInput() {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        int[] a = new int[n];
        for(int i = 0; i < n; i++) {
            a[i] = s.nextInt();
        }
        return a;
    }
    
    public static int bubbleSort(int[] a) {
        int swaps = 0;
        for(int i = 0; i < a.length; i++) {
            for(int  j = 0; j < a.length - 1; j++) {
                if(a[j] > a[j + 1]) {
                    int tmp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = tmp;
                    swaps++;
                }
            }
        }
        return swaps;
    }
    
    public static void main(String[] args) {
        int[] a = readInput();
        int swaps = bubbleSort(a);
        System.out.format("Array is sorted in %d swaps.\nFirst Element: %d\nLast Element: %d\n", swaps, a[0], a[a.length - 1]);
    }
}
