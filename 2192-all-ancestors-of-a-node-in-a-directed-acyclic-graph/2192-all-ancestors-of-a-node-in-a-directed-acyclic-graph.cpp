class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> graph;

        for (int i = 0; i < n; i++) {
            graph[i] = {};
        }
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            graph[u].push_back(v);
        }

        vector<int> indegree(n);
        for(int i=0;i<n;i++){
            for(int x: graph[i]){
                indegree[x]++;
            }
        }

        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        vector<set<int>> ancestor(n);

        while(!q.empty()){
            int rv=q.front(); q.pop();

            for(int nbr: graph[rv]){
                ancestor[nbr].insert(rv);

                for(int x: ancestor[rv]){
                    ancestor[nbr].insert(x);
                }

                indegree[nbr]--;
                if(indegree[nbr]==0){
                    q.push(nbr);
                }
            }

        }
        vector<vector<int>> ans(n);
        for(int i=0;i<n;i++){
            ans[i] = vector<int>(ancestor[i].begin(), ancestor[i].end());
        }
        return ans;
    }
};