class Solution {
    public int makeConnected(int n, int[][] connections) {
        if (connections.length < n - 1) {
            return -1;
        }
        HashMap<Integer, List<Integer>> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            map.put(i, new ArrayList<>());
        }

        for (int i = 0; i < connections.length; i++) {
            int u = connections[i][0];
            int v = connections[i][1];

            map.get(u).add(v);
            map.get(v).add(u);
        }
        return connect(n,connections.length, map);
    }

    public int connect(int n, int totaledge,HashMap<Integer, List<Integer>> map) {
        HashSet<Integer> visited = new HashSet<>();
        int count=0;
        for (int i = 0; i < n; i++) {
            if(visited.contains(i)){
                continue;
            }
            Queue<Integer> q = new LinkedList<>();
            q.add(i);
            count++;
            while(!q.isEmpty()){
                int rv=q.poll();
                if(visited.contains(rv)){
                    continue;
                }
                visited.add(rv);
                for(int nbr: map.get(rv)){
                    if(!visited.contains(nbr)){
                        q.add(nbr);
                    }
                }
            }
        }
        return count-1;
    }
}