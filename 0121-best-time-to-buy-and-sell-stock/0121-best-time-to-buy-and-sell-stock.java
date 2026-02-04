class Solution {
    public int maxProfit(int[] arr) {
        int n= arr.length;
        int ans=Integer.MIN_VALUE;
        int min=arr[0];
        for(int i=0;i<arr.length;i++){
            if(arr[i]<min){
                min=arr[i];
            }
            int diff=arr[i]-min;
            ans=Math.max(ans,diff);
           
        }
        return ans;
    }
}