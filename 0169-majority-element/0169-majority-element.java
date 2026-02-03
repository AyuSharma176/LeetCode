class Solution {
    public int majorityElement(int[] nums) {
        int n=nums.length;
        HashMap<Integer,Integer> map = new HashMap<>();
        for(int x:nums){
            map.put(x,map.getOrDefault(x,0)+1);
        }
        int ans=0;
        for(int x: map.keySet()){
            if(map.get(x)>(n/2)){
                ans=x;
                break;
            }
        }
        return ans;
    }
}