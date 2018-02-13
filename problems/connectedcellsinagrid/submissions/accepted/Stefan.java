// Author: Stefan Toman

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Stefan {
    
    static class Pair<S, T> {
        public S a;
        public T b;
        
        public Pair(S a, T b) {
            this.a = a;
            this.b = b;
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();
        int grid[][] = new int[n][m];
        for(int grid_i=0; grid_i < n; grid_i++){
            for(int grid_j=0; grid_j < m; grid_j++){
                grid[grid_i][grid_j] = in.nextInt();
            }
        }
        
        //start solution
        boolean visited[][] = new boolean[n][m];
        int maxRegion = 0;
        for(int grid_i=0; grid_i < n; grid_i++){
            for(int grid_j=0; grid_j < m; grid_j++){
                if(!visited[grid_i][grid_j] && grid[grid_i][grid_j] == 1) {
                    int region = 1;
                    visited[grid_i][grid_j] = true;
                    Queue<Pair<Integer, Integer>> q = new LinkedList<Pair<Integer, Integer>>();
                    q.add(new Pair<Integer, Integer>(grid_i, grid_j));
                    while(!q.isEmpty()) {
                        Pair<Integer, Integer> p = q.poll();
                        for(int di = p.a == 0 ? 0 : -1; di <= Math.min(1, n - p.a - 1); di++) {
                            for(int dj = p.b == 0 ? 0 : -1; dj <= Math.min(1, m - p.b - 1); dj++) {
                                if(dj != 0 || di != 0) {
                                    if(!visited[p.a + di][p.b + dj] && grid[p.a + di][p.b + dj] == 1) {
                                        region++;
                                        visited[p.a + di][p.b + dj] = true;
                                        q.add(new Pair<Integer, Integer>(p.a + di, p.b + dj));
                                    }
                                }    
                            }
                        }
                    }
                    if(region > maxRegion) {
                        maxRegion = region;
                    }
                }
            }
        }
        System.out.println(maxRegion);
    }
}
