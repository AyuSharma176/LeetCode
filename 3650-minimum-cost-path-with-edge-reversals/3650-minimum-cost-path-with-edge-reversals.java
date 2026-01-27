import java.util.*;

class Solution {

    class Pair {
        int node;
        int used;
        int cost;

        Pair(int node, int used, int cost) {
            this.node = node;
            this.used = used;
            this.cost = cost;
        }
    }

    public int minCost(int n, int[][] edges) {

        List<int[]>[] graph = new ArrayList[n];
        List<int[]>[] reverseGraph = new ArrayList[n];

        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<>();
            reverseGraph[i] = new ArrayList<>();
        }

        for (int[] e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            graph[u].add(new int[] { v, w });
            reverseGraph[v].add(new int[] { u, w });
        }

        int[][] dist = new int[n][2];
        for (int i = 0; i < n; i++) {
            dist[i][0] = dist[i][1] = Integer.MAX_VALUE;
        }
        dist[0][0] = 0;

        solve(dist, graph, reverseGraph, n);

        int ans = Math.min(dist[n - 1][0], dist[n - 1][1]);
        return ans == Integer.MAX_VALUE ? -1 : ans;
    }

    public void solve(int[][] dist, List<int[]>[] graph, List<int[]>[] reverseGraph, int n) {

        PriorityQueue<Pair> pq = new PriorityQueue<>(
                (a, b) -> a.cost - b.cost);

        pq.add(new Pair(0, 0, 0));

        while (!pq.isEmpty()) {
            Pair rv = pq.poll();

            if (rv.cost > dist[rv.node][rv.used])
                continue;

            for (int[] edge : graph[rv.node]) {
                int next = edge[0];
                int w = edge[1];
                if (dist[next][0] > rv.cost + w) {
                    dist[next][0] = rv.cost + w;
                    pq.add(new Pair(next, 0, dist[next][0]));
                }
            }

            if (rv.used == 0) {
                for (int[] edge : reverseGraph[rv.node]) {
                    int next = edge[0];
                    int w = edge[1];
                    if (dist[next][0] > rv.cost + 2 * w) {
                        dist[next][0] = rv.cost + 2 * w;
                        pq.add(new Pair(next, 0, dist[next][0]));
                    }
                }
            }

        }
    }
}
