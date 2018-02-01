//Author: Stefan Toman

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Stefan {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int a[] = new int[n];
        for(int a_i=0; a_i < n; a_i++){
            a[a_i] = in.nextInt();
        }
        
        HashSet<Integer> numbers = new HashSet<Integer>();
        for(int t: a) {
            if(numbers.contains(t)) {
                numbers.remove(t);
            }
            else {
                numbers.add(t);
            }
        }
        System.out.println(numbers.toArray()[0]);
    }
}
