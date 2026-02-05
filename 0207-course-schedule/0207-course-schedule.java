class Solution {
    public boolean canFinish(int numCourses, int[][] p) {
        List<List<Integer>> adj = new ArrayList<>();
        for(int i=0;i<numCourses;i++){
            adj.add(new ArrayList<>());
        }

        for(int[] pre: p){
            int course=pre[0];
            int req=pre[1];
            adj.get(req).add(course);
        }
        int completed=topo(numCourses,adj);
        return completed==numCourses;
    }
    public int topo(int v,List<List<Integer>> adj){
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
        int count =0;
        while(!q.isEmpty()){
            int rv = q.poll();

            count++;

            for(int nbr: adj.get(rv)){
                indegree[nbr]--;
                if(indegree[nbr]==0){
                    q.add(nbr);
                }
            }
        }
        return count;
    }
}