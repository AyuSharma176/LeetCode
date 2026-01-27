import java.util.*;

class Solution {

    class Pair {
        int vtx;
        int dist;

        Pair(int vtx, int dist) {
            this.vtx = vtx;
            this.dist = dist;
        }
    }

    public int[] BFS(int src, HashMap<Integer, ArrayList<Integer>> map, int n) {
        HashSet<Integer> visited = new HashSet<>();
        Queue<Pair> q = new LinkedList<>();

        int[] dist = new int[n];
        Arrays.fill(dist, -1);

        q.add(new Pair(src, 0));

        while (!q.isEmpty()) {
            Pair rv = q.poll();

            if (visited.contains(rv.vtx))
                continue;

            visited.add(rv.vtx);
            dist[rv.vtx] = rv.dist;

            for (int nbr : map.get(rv.vtx)) {
                if (!visited.contains(nbr)) {
                    q.add(new Pair(nbr, rv.dist + 1));
                }
            }
        }
        return dist;
    }

    public int specialNodes(int n, int[][] edges, int x, int y, int z) {

        HashMap<Integer, ArrayList<Integer>> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            map.put(i, new ArrayList<>());
        }

        for (int i = 0; i < edges.length; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            map.get(u).add(v);
            map.get(v).add(u);
        }
        int[] dx = BFS(x, map, n);
        int[] dy = BFS(y, map, n);
        int[] dz = BFS(z, map, n);

        int count = 0;

        for (int i = 0; i < n; i++) {
            int[] arr = { dx[i], dy[i], dz[i] };
            Arrays.sort(arr);

            int a = arr[0];
            int b = arr[1];
            int c = arr[2];

            if (a * a + b * b == c * c) {
                count++;
            }
        }

        return count;
    }
}
