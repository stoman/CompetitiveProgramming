import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class ManicMovingEmi {
	
	static class FloydWarshall {

	    // graph represented by an adjacency matrix
	    private int[][] graph;
	    private boolean negativeCycle;

	    public FloydWarshall(int n) {
	        this.graph = new int[n][n];
	        initGraph();
	    }

	    private void initGraph() {
	        for (int i = 0; i < graph.length; i++) {
	            for (int j = 0; j < graph.length; j++) {
	                if (i == j) {
	                    graph[i][j] = 0;
	                } else {
	                    graph[i][j] = Integer.MAX_VALUE;
	                }
	            }
	        }
	    }

	    public boolean hasNegativeCycle() {
	        return this.negativeCycle;
	    }

	    // utility function to add edges to the adjacencyList
	    public void addEdge(int from, int to, int weight) {
	        graph[from][to] = Math.min(graph[from][to], weight);
	        graph[to][from] = Math.min(graph[to][from], weight);
	    }

	    // all-pairs shortest path
	    public int[][] floydWarshall() {
	        int[][] distances;
	        int n = this.graph.length;
	        distances = Arrays.copyOf(this.graph, n);

	        for (int k = 0; k < n; k++) {
	            for (int i = 0; i < n; i++) {
	                for (int j = 0; j < n; j++) {
	                	if (distances[i][k] < Integer.MAX_VALUE && distances[k][j] < Integer.MAX_VALUE) {
	                		distances[i][j] = Math.min(distances[i][j], distances[i][k] + distances[k][j]);
	                	}
	                }
	            }

	            if (distances[k][k] < 0) {
	                this.negativeCycle = true;
	            }
	        }

	        return distances;
	    }

	}
	
	public static void main(String[] args) throws IOException {
		String file = "manic_moving";
		Scanner sc = new Scanner(System.in);

		int t = sc.nextInt();

		for (int c = 1; c <= t; c++) {
			
			int n = sc.nextInt();
			int m = sc.nextInt();
			int k = sc.nextInt();
			
			FloydWarshall fw = new FloydWarshall(n);
			for (int i = 0; i < m; i++) {
				int from = sc.nextInt() - 1;
				int to = sc.nextInt() - 1;
				fw.addEdge(from, to, sc.nextInt());
			}
			
			int[] froms = new int[k + 1];
			int[] tos = new int[k + 1];
			
			for (int i = 1; i <= k; i++) {
				froms[i] = sc.nextInt() - 1;
				tos[i] = sc.nextInt() - 1;
			}
			int[][] distances = fw.floydWarshall();
			
			boolean imp = false;
			for (int i : froms) {
				if (distances[0][i] == Integer.MAX_VALUE) {
					imp = true;
				}
			}
			for (int i : tos) {
				if (distances[0][i] == Integer.MAX_VALUE) {
					imp = true;
				}
			}
			if (imp) {
				System.out.println("Case #" + c + ": -1");
				continue;
			}
			
			long dp[][] = new long[k + 1][4];
			for (int i = 0; i <= k; i++) {
				// i finished, empty if unload from i-1 finished, load 1
				if (i > 0) {
					// now empty, so just unloaded i
					long dist1 = dp[i - 1][1] + distances[froms[i]][tos[i]];
					long dist2 = dp[i - 1][2] + distances[tos[i - 1]][tos[i]];
					dp[i][0] = Math.min(dist1, dist2);
				}
				if (i < k) {
					// i finished
					if (i > 0) {
						// v1: loaded
						dp[i][1] = dp[i][0] + distances[tos[i]][froms[i+1]];
						// v2: unloaded
						dp[i][2] = dp[i - 1][3] + distances[froms[i + 1]][tos[i]];
					} else {
						dp[0][1] = distances[0][froms[1]];
						dp[0][2] = Integer.MAX_VALUE;
					}
				}
				if (i < k - 1) {
					// i finished, load 2
					long dist1 = dp[i][1] + distances[froms[i + 1]][froms[i + 2]];
					long dist2 = dp[i][2] + distances[tos[i]][froms[i + 2]];
					dp[i][3] = Math.min(dist1, dist2);
				}
			}
//			output(dp);
//			System.out.println("Case #" + c + ": " + dp[k][0]);
			System.out.println("Case #" + c + ": " + dp[k][0]);
			
		}

		sc.close();
	}
	
	
	private static void output(long[][] dp) {
		for (int i = 0; i < dp.length; i++) {
			for (int j = 0; j < dp[i].length; j++) {
				if (dp[i][j] >= Integer.MAX_VALUE) {
					System.out.print("X");
				} else {
					System.out.print(dp[i][j]);
				}
				System.out.print(" ");
			}
			System.out.println();
		}
	}
}
