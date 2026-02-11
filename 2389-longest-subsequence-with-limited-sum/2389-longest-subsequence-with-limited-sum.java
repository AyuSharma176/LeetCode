class Solution {
    public int[] answerQueries(int[] nums, int[] queries) {
        int n=nums.length;
        int m=queries.length;
        Arrays.sort(nums);
        int[] ans = new int[m];
        for(int i=0;i<m;i++){
            int sum=0;
            int k=queries[i];
            int size=0;
            int max=Integer.MIN_VALUE;
            
            for(int j=0;j<n;j++){
                sum+=nums[j];
                if(sum>k){
                    sum-=nums[j];
                    size--;
                }
                if(sum<=k){
                    // System.out.print(sum+" ");
                    size++;
                    max=size;
                }
            }
            ans[i]=max;
        }
        return ans;
    }
}