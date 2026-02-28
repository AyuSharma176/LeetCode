class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& connect) {
        vector<vector<int>> ans;
        vector<int> path;

        dfs(0,connect,ans,path);
        return ans;
    }
    void dfs(int src,vector<vector<int>>& connect,vector<vector<int>>& ans,vector<int>& path){
        path.push_back(src);

        if(src==connect.size()-1){
            ans.push_back(path);
        }else{
            for(int nbr: connect[src]){
                dfs(nbr,connect,ans,path);
            }
        }
        path.pop_back();
    }
};