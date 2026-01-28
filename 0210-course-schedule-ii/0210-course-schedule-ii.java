class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        List<List<Integer>> adj = new ArrayList<>();

        for(int i=0;i<numCourses;i++){
            adj.add(new ArrayList<>());
        }

        for(int [] pre: prerequisites){
            int course = pre[0];
            int prerequi = pre[1];

            adj.get(prerequi).add(course);
        }
        List<Integer> topo=solve(numCourses,adj);

        if(topo.size()!=numCourses){
            return new int[0];
        }
        int[] ans = new int[topo.size()];
        for(int i=0;i<topo.size();i++){
            ans[i]=topo.get(i);
        }
        return ans;
    }
    public List<Integer> solve(int v,List<List<Integer>> adj){
        int[] indegree=new int[v];

        for(int i=0;i<v;i++){
            for(int nbr: adj.get(i)){
                indegree[nbr]++;
            }
        }
        Queue<Integer> q = new LinkedList<>();
        for(int i=0;i<v;i++){
            if(indegree[i]==0){
                q.add(i);
            }
        }

        List<Integer> topo = new ArrayList<>();
        int count=0;
        while(!q.isEmpty()){
            int rv=q.poll();

            topo.add(rv);
            for(int nbr: adj.get(rv)){
                indegree[nbr]--;
                if(indegree[nbr]==0){
                    q.add(nbr);
                }
            }
        }

        return topo;
    }

}