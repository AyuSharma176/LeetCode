class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int totalsum=0;
        for(int i=0;i<nums.size();i++){
            totalsum+=nums[i];
        }
        if(totalsum%2!=0){
            return false;
        }
        int target=totalsum/2;
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return solve(nums,target,0,dp);

    }
    bool solve(vector<int>& nums,int target,int i,vector<vector<int>>& dp){
        if(i>=nums.size()){
            return false;
        }
        if(target==0){
            return true;
        }
        if(dp[i][target]!=-1){
            return dp[i][target];
        }
        bool inc=false;
        if(nums[i]<=target){
            inc=solve(nums,target-nums[i],i+1,dp);
        }
        bool ninc=solve(nums,target,i+1,dp);

        return dp[i][target]=inc||ninc;
    }
};