class Solution {
public:
    int maxi=0;
    int sum=0;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    sum=0;
                    dfs(grid,i,j);
                }
            }
        }
        return maxi;
    }
    void dfs(vector<vector<int>>& grid,int i,int j){
        if(i<0 || j<0 || i>=grid.size()||j>=grid[i].size()||grid[i][j]==0){
            return;
        }
        sum+=grid[i][j];
        grid[i][j]=0;
        maxi=max(maxi,sum);
        dfs(grid,i+1,j);
        dfs(grid,i-1,j);
        dfs(grid,i,j+1);
        dfs(grid,i,j-1);
        
    }
};