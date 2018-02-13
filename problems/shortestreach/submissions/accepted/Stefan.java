// Author: Stefan Toman

import java.io.*;
import java.util.*;

public class Stefan {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int q = sc.nextInt();
        for(int qq = 0; qq < q; qq++) {
            int n = sc.nextInt();
            int m = sc.nextInt();
            List<Integer>[] adj = new List[n];
            for(int i = 0; i < n; i++) {
                adj[i] = new LinkedList<Integer>();
            }
            for(int i = 0; i < m; i++) {
                int u = sc.nextInt() - 1;
                int v = sc.nextInt() - 1;
                adj[u].add(v);
                adj[v].add(u);
            }
            int s = sc.nextInt() - 1;
            int[] dist = new int[n];
            Arrays.fill(dist, -1);
            boolean[] visited = new boolean[n];

            Queue<Integer> qu = new LinkedList<Integer>();
            qu.add(s);
            dist[s] = 0;
            visited[s] = false;
            while(!qu.isEmpty()) {
                int c = qu.poll();
                for(int neigh: adj[c]) {
                    if(!visited[neigh]) {
                        visited[neigh] = true;
                        dist[neigh] = dist[c] + 6;
                        qu.add(neigh);
                    }
                }
            }
            
            for(int i = 0; i < n; i++) {
                if(i != s) {
                    System.out.print(dist[i]);
                    System.out.print(i == n - 1 ? "\n" : " ");
                }
            }
        }
    }
}
