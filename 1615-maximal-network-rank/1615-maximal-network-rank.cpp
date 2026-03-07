class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < roads.size(); i++) {
            int u = roads[i][0];
            int v = roads[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> degree(n);
        for (int i = 0; i < n; i++) {
            degree[i] = adj[i].size();
        }
        int maxnum = INT_MIN;
        pair<int, int> p;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int rank = degree[i] + degree[j];
                p.first = i;
                p.second = j;
                if (haspath(p,adj)) {
                    rank--;
                }
                maxnum=max(maxnum,rank);
            }
        }
        return maxnum;
    }
    bool haspath(pair<int, int>& p, vector<vector<int>>& adj) {
        bool a = find(adj[p.first].begin(), adj[p.first].end(), p.second) !=
                 adj[p.first].end();
        bool b = find(adj[p.second].begin(), adj[p.second].end(), p.first) !=
                 adj[p.second].end();

        return a && b;
    }
};