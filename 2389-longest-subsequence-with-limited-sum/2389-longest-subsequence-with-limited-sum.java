class Solution {
    public int[] answerQueries(int[] nums, int[] queries) {
        int n=nums.length;
        int m=queries.length;
        Arrays.sort(nums);
        for(int i = 1; i < n; i++) nums[i] += nums[i - 1];
        

        for(int i=0;i<m;i++){
            int index= Arrays.binarySearch(nums,queries[i]+1);
            if(index<0) index= ~index;
            queries[i]=index;
        }
        return queries;
    }
}