class Solution {
    public int[] findRedundantDirectedConnection(int[][] edges) {
        HashMap<Integer,List<Integer>> map = new HashMap<>();
        int n = edges.length;
        for(int i=1;i<=n;i++){
            map.put(i,new ArrayList<>());
        }
        int[] parent = new int[n+1];
        Arrays.fill(parent,-1);
        int[] edges1=null;
        int[] edges2=null;
        for(int[] e: edges){
            int u=e[0];
            int v=e[1];

            if(parent[v]==-1){
                parent[v]=u;
            }else{
                edges1=new int[]{parent[v],v};
                edges2=new int[]{u,v};
                e[1]=0;
            }
        }
        for(int[] e:edges){
            int u=e[0];
            int v=e[1];
            if(v==0) continue;
            if(hasPath(v,u,map,new HashSet<>())){
                return edges1==null?e:edges1;
            }
            map.get(u).add(v);
        }
        return edges2;
    }

    public boolean hasPath(int src,int des,HashMap<Integer,List<Integer>> map,HashSet<Integer> visited){
        if(src==des){
            return true;
        }

        visited.add(src);

        for(int nbr: map.get(src)){
            if(!visited.contains(nbr)){
                if(hasPath(nbr,des,map,visited)){
                    return true;
                }
            }
        }
        return false;
    }
}