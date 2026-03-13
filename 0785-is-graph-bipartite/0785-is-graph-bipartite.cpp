class Solution {
public:
    
    bool isBipartite(vector<vector<int>>& graph) {
        map<int,int> visited;
        queue<pair<int,int>> q;
        for(int v=0;v<graph.size();v++){
            if(visited.contains(v)){
                continue;
            }
            q.push({v,0});
            while(!q.empty()){
                auto& rv=q.front();
                int vtx=rv.first;
                int dist=rv.second;
                q.pop();

                if(visited.contains(vtx)){
                    if(visited[vtx]!=dist) return false;
                    else continue;
                }
                visited[vtx]=dist;
                for(int nbrs: graph[vtx]){
                    if(!visited.contains(nbrs)){
                        q.push({nbrs,dist+1});
                    }
                }
            }
        }
        return true;
    }
};