class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();

        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));

        // Pacific (top row)
        for(int i = 0; i < m; i++){
            dfs(0, i, pacific, v);
        }

        // Pacific (left column)
        for(int i = 0; i < n; i++){
            dfs(i, 0, pacific, v);
        }

        // Atlantic (bottom row)
        for(int j = 0; j < m; j++){
            dfs(n-1, j, atlantic, v);
        }

        // Atlantic (right column)
        for(int i = 0; i < n; i++){
            dfs(i, m-1, atlantic, v);
        }

        vector<vector<int>> result;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(pacific[i][j] && atlantic[i][j]){
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }

    void dfs(int r, int c, vector<vector<bool>>& visited, vector<vector<int>>& v){

        if(visited[r][c]) return;

        visited[r][c] = true;

        int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        for(auto &d : dir){

            int nr = r + d[0];
            int nc = c + d[1];

            if(nr < 0 || nc < 0 || nr >= v.size() || nc >= v[0].size())
                continue;

            if(visited[nr][nc])
                continue;

            if(v[nr][nc] < v[r][c])
                continue;

            dfs(nr, nc, visited, v);
        }
    }
};