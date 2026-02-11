class Solution {
    public int[] answerQueries(int[] nums, int[] queries) {
        int n=nums.length;
        int m=queries.length;
        Arrays.sort(nums);
        int[] sum = new int[n+1];
        for(int i=0;i<n;i++) sum[i+1]=sum[i]+nums[i];
        int[] ans = new int[m];

        for(int i=0;i<m;i++){
            int index= Arrays.binarySearch(sum,queries[i]+1);
            if(index<0) index= ~index;
            ans[i]=index-1;
        }
        return ans;
    }
}