class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();

        queue<vector<int>> q;
        int fresh=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
        int min=0;
        while(!q.empty()){
            int size=q.size();
            bool rotten=false;
            while(size-->0){
                vector<int> rv=q.front();q.pop();
                int r=rv[0];
                int c=rv[1];
                for(vector<int> d:dir){
                    int nr=r+d[0];
                    int nc=c+d[1];

                    if(nr>=0 && nr<rows && nc>=0 && nc<cols && grid[nr][nc]==1){
                        grid[nr][nc]=2;
                        q.push({nr,nc});
                        fresh--;
                        rotten=true;
                    }
                }
            }
            if(rotten) min++;
        }
        if(fresh==0){
            return min;
        }
        return -1;
    }
};