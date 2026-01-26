class Solution {
    public int minimumPrefixLength(int[] nums) {
        int n=nums.length;
        int count =0;
        for(int i=0;i<n-1;i++){
            if(nums[i]<nums[i+1]){
                count++;
            }else{
                count=0;
            }
        }
        
        return n-count-1;
    }
}