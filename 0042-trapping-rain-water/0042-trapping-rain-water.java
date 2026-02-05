class Solution {
    public int trap(int[] height) {
        int n=height.length;
        int[] frontmax=new int[n];
        int[] backmax=new int[n];
        frontmax[0]=height[0];
        for(int i=1;i<n;i++){
            frontmax[i]=Math.max(frontmax[i-1],height[i]);
        }
        backmax[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            backmax[i]=Math.max(backmax[i+1],height[i]);
        }

        int sum =0;
        for(int i=0;i<n;i++){
            sum+=Math.min(frontmax[i],backmax[i])-height[i];
        }
        return sum;
    }
}