class Solution {
public:
    vector<vector<int>> reverse;
    vector<int> indegree;
    vector<int> ans;
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<int> q;
        init(graph);
        for(int i =0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int rv = q.front(); q.pop();
            ans.push_back(rv);

            for(int v: reverse[rv]){
                indegree[v]--;
                if(indegree[v]==0) q.push(v);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
    void init(vector<vector<int>>& graph){
        indegree = vector<int>(graph.size(),0);
        reverse.resize(graph.size(),vector<int>(0));

        for(int u=0;u<graph.size();u++){
            for(int v:graph[u]){
                reverse[v].push_back(u);
                indegree[u]++;
            }
        }
    }
};