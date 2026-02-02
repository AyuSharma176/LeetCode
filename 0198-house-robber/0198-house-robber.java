class Solution {
    public int rob(int[] nums) {
        int[] dp = new int[nums.length+1];
        Arrays.fill(dp,-1);

        return robbing(nums,0,dp);
    }
    public int robbing(int[] nums,int i,int[] dp){
        if(i>=nums.length){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        
        int inc=nums[i]+robbing(nums,i+2,dp);
        int ni=robbing(nums,i+1,dp);
     
        dp[i]=Math.max(ni,inc);
        return dp[i];
    }
}