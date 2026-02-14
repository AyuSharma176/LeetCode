class Solution {
    public int findTheCity(int n, int[][] edges, int dt) {
        ArrayList<ArrayList<int[]>> adj = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            adj.add(i, new ArrayList<>());
        }
        for (int i = 0; i < edges.length; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            adj.get(u).add(new int[] { v, w });
            adj.get(v).add(new int[] { u, w });
        }
        int minCount = Integer.MAX_VALUE;
        int ans = -1;

        for (int i = 0; i < n; i++) {
            int count = dij(n, adj, i, dt);
            if (count <= minCount) {
                minCount = count;
                ans = i;
            }
        }
        return ans;
    }

    public int dij(int n, ArrayList<ArrayList<int[]>> adj, int src, int dt) {
        PriorityQueue<int[]> q = new PriorityQueue<>((a,b) -> a[1] - b[1]);
        int[] dist = new int[n];
        Arrays.fill(dist, (int)1e9);
        dist[src] = 0;
        q.add(new int[] { src, 0 });
        while (!q.isEmpty()) {
            int[] rv = q.poll();
            int vtx = rv[0];
            int d = rv[1];
            if (d > dist[vtx]) {
                continue;
            }
           
            for (int[] nbr : adj.get(vtx)) {
                int next = nbr[0];
                int wt = nbr[1];
                if (dist[vtx] + wt < dist[next]) {
                    dist[next] = dist[vtx] + wt;
                    q.add(new int[] { next, dist[next] });
                }
            }
        }
        int count=0;
        for (int j = 0; j < n; j++) {
            if (j != src && dist[j] <= dt) {
                count++;
            }

        }
        return count;
    }

}