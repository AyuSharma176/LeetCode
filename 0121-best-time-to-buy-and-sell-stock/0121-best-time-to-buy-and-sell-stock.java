class Solution {
    public int maxProfit(int[] prices) {
        int max=Integer.MIN_VALUE;
        int diff=0;
        int min=prices[0];
        for(int i=0;i<prices.length;i++){
            if(prices[i]<min){
                min=prices[i];
            }
            diff=prices[i]-min;
            max=Math.max(max,diff);
        }
        return max;
    }
}