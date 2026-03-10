class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return climb(n,0,dp);
    }
    int climb(int n,int i, vector<int>& dp){
        if(i==n){
            return 1;
        }
        if(i>n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int x1=climb(n,i+1,dp);
        int x2=climb(n,i+2,dp);
        return dp[i]=x1+x2;
    }
};