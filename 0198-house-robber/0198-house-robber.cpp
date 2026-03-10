class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1); 
        return robbery(nums,0,dp);
    }
    int robbery(vector<int>& nums , int i,vector<int>& dp){

        if(i>=nums.size()){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        int c1=nums[i]+robbery(nums,i+2,dp);
        int c2=robbery(nums,i+1,dp);
        return dp[i]=max(c1,c2);
    }
};