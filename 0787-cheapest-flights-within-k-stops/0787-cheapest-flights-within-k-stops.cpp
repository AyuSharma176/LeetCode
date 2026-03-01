class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        unordered_map<int, unordered_map<int, int>> graph;
        for (int i = 0; i < n; i++) {
            graph[i] = unordered_map<int, int>();
        }
        for (vector<int>& e : flights) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            graph[u][v] = w;
        }
        return pathWeight(n,graph,src,dst,k);
    }
    int pathWeight(int n,unordered_map<int, unordered_map<int, int>>& graph, int src,
                   int des, int k) {
        priority_queue<vector<int>, vector<vector<int>>,
                       greater<vector<int>>>
            pq;

        // unordered_set<int> visited;
        pq.push({0, src, 0});
        vector<int> minStops(n, INT_MAX);
        while (!pq.empty()) {
            auto top = pq.top();
            int dist = top[0];
            int node = top[1];
            int stops = top[2];
            pq.pop();
            if (stops > minStops[node]) {
                continue;
            }
            minStops[node]=stops;
            if (node == des) {
                return dist;
            }
            for (auto& nbr : graph[node]) {
                if (stops <= k) {
                    pq.push({dist + nbr.second, nbr.first, stops+1});
                }
            }
        }
        return -1;
    }
};