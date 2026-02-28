class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int,vector<int>> graph;
        int n=isConnected.size();
        for(int i=1;i<=n;i++){
            graph[i]=vector<int>();
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<isConnected[0].size();j++){
                if(isConnected[i-1][j]==1){
                    graph[i].push_back(j+1);
                }
            }
        }
        
        return bfs(graph);
    }
    int bfs(unordered_map<int,vector<int>> &graph){
        unordered_set<int> visited;
        queue<int> q;
        int count=0;
        for(auto &it: graph){
            int node = it.first;
            if(visited.count(node)) continue;
            count++;
            q.push(node);
            visited.insert(node);
            while(!q.empty()){
                int curr=q.front();
                q.pop();
                for(auto nbr: graph[curr]){
                    if(!visited.count(nbr)){
                        visited.insert(nbr);
                        q.push(nbr);
                    }
                }
            }
        }
        return count;
    }
};