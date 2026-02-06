class Solution {
    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        if (n <= 2) {
            List<Integer> res = new ArrayList<>();
            for (int i = 0; i < n; i++)
                res.add(i);
            return res;
        }
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }
        int[] indegree = new int[n];
        for (int[] e : edges) {
            int u = e[0];
            int v = e[1];

            adj.get(u).add(v);
            adj.get(v).add(u);
            indegree[u]++;
            indegree[v]++;
        }
        return topo(n, adj, indegree);
    }

    public List<Integer> topo(int n, List<List<Integer>> adj, int[] indegree) {
        int count = n;
        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 1) {
                q.add(i);
            }
        }
        while (count > 2) {
            int size = q.size();
            count -= size;
            while (size-- > 0) {
                int rv = q.poll();
                indegree[rv] = 0;
                for (int nbr : adj.get(rv)) {
                    indegree[nbr]--;
                    if (indegree[nbr] == 1) {
                        q.add(nbr);
                    }
                }
            }
        }
        // List<Integer> l = new ArrayList<>();
        // for(int i=0;i<n;i++){
        //     if(indegree[i]>0){
        //         l.add(i);
        //     }
        // }
        return new ArrayList<>(q);
    }

}