//Author: Stefan Toman

import java.util.*;

public class Stefan {
    private static HashMap<Integer, Integer> mem = new HashMap<Integer, Integer>();
    
    public static int fibonacci(int n) {
        if(n == 0 || n == 1) {
            return n;
        }
        if(!mem.containsKey(n)) {
            mem.put(n, fibonacci(n - 1) + fibonacci(n - 2));
        }
        return mem.get(n);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.close();
        System.out.println(fibonacci(n));
    }
}
