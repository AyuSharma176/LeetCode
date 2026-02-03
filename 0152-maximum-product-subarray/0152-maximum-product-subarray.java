class Solution {
    public int maxProduct(int[] nums) {
        int maxp=nums[0];
        int minp=nums[0];
        int ans=maxp;
        for(int i=1;i<nums.length;i++){
            int c=nums[i];
            if(c<0){
                int temp=maxp;
                maxp=minp;
                minp=temp;
            }
            maxp=Math.max(c,maxp*c);
            minp=Math.min(c,minp*c);
            ans=Math.max(ans,maxp);
        }
        return ans;
    }
}