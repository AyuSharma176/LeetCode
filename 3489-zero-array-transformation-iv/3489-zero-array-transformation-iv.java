class Solution {
    public int solve(int idx, int k, int target, int[][] q, int[][] dp) {
        if (target == 0) {
            return k;
        }
        if (k >= q.length || target < 0) {
            return q.length + 1;
        }
        if (dp[target][k] != -1) {
            return dp[target][k];
        }

        int res = solve(idx, k + 1, target, q, dp);

        if (q[k][0] <= idx && q[k][1] >= idx) {
            res = Math.min(res, solve(idx, k + 1, target - q[k][2], q, dp));
        }
        dp[target][k] = res;
        return res;
    }

    public int minZeroArray(int[] nums, int[][] q) {
        int n = nums.length;
        int m = q.length;
        int ans = Integer.MIN_VALUE;
        for (int i = 0; i < n; i++) {
            int[][] dp = new int[nums[i] + 1][m];

            for (int t = 0; t <= nums[i]; t++) {
                for (int p = 0; p < m; p++) {
                    dp[t][p] = -1;
                }
            }
            ans = Math.max(ans, solve(i, 0, nums[i], q, dp));
        }
        return (ans > q.length) ? -1 : ans;
    }
}