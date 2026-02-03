class Solution {
    public boolean isTrionic(int[] nums) {
        
        int inc=0;
        int n = nums.length;
        int p=-1;
        for(int i=0;i<n-1;i++){
            if(nums[i]<nums[i+1]){
                inc++;
            }
            if(nums[i]==nums[i+1]){
                return false;
            }
            if(nums[i]>nums[i+1]){
                p=i;
                break;
            }
        }
        int dec=0;
        int q=-1;
        if(p==-1){
            return false;
        }
        for(int i=p;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                dec++;
            }
            if(nums[i]==nums[i+1]){
                return false;
            }
            if(nums[i]<nums[i+1]){
                q=i;
                break;
            }
        }
        if(q==-1){
            return false;
        }
        int lastinc=0;
        for(int i=q;i<n-1;i++){
            if(nums[i]<nums[i+1]){
                lastinc++;
            }
            
            if(nums[i]>=nums[i+1]){
                return false;
            }
        }
        if(inc!=0 && dec!=0 && lastinc!=0){
            return true;
        }
        return false;
    }
}