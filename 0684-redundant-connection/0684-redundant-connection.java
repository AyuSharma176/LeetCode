class Solution {
    public int[] findRedundantConnection(int[][] edges) {
        HashMap<Integer, List<Integer>> graph = new HashMap<>();

        for (int i = 1; i <= edges.length; i++) {
            graph.put(i, new ArrayList<>());
        }

        for (int[] e : edges) {
            int u = e[0];
            int v = e[1];
            if(hasPath(u,v,graph,new HashSet<>())){
                return new int[]{u,v};
            }
            graph.get(u).add(v);
            graph.get(v).add(u);
        }
        return new int[0];

    }

    public boolean hasPath(int src, int dest,
            HashMap<Integer, List<Integer>> graph,
            HashSet<Integer> visited) {

        if (src == dest)
            return true;

        visited.add(src);

        for (int nbr : graph.get(src)) {
            if (!visited.contains(nbr)) {
                if (hasPath(nbr, dest, graph, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
}