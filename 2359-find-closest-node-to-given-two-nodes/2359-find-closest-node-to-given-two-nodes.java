class Solution {
    class Pair {
        Integer vtx;
        Integer dist;

        Pair(Integer vtx, Integer dist) {
            this.vtx = vtx;
            this.dist = dist;
        }
    }

    public Integer[] BFS(int src, HashMap<Integer, Integer> map, int n) {
        HashSet<Integer> visited = new HashSet<>();
        Queue<Pair> q = new LinkedList<>();

        Integer[] dist = new Integer[n];
        Arrays.fill(dist, -1);

        q.add(new Pair(src, 0));

        while (!q.isEmpty()) {
            Pair rv = q.poll();

            if (visited.contains(rv.vtx))
                continue;

            visited.add(rv.vtx);
            dist[rv.vtx] = rv.dist;
            Integer nbr = map.get(rv.vtx);
            if (nbr != null && !visited.contains(nbr)) {
                q.add(new Pair(nbr, rv.dist + 1));
            }

        }
        return dist;
    }

    public int closestMeetingNode(int[] edges, int node1, int node2) {
        int n = edges.length;
        HashMap<Integer, Integer> map = new HashMap<>();

        for (int i = 0; i < n; i++) {
            if (edges[i] != -1) {
                map.put(i, edges[i]);
            }
        }
        Integer[] d1 = BFS(node1, map, n);
        Integer[] d2 = BFS(node2, map, n);
        int minDist = Integer.MAX_VALUE;
        int res = -1;

        for (int i = 0; i < n; i++) {
            if (d1[i] == -1 || d2[i] == -1)
                continue;

            int maxDist = Math.max(d1[i], d2[i]);

            if (maxDist < minDist) {
                minDist = maxDist;
                res = i;
            }
        }
        return res;
    }
}