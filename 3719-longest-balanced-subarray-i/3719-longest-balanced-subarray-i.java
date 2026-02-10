class Solution {
    public int longestBalanced(int[] nums) {
        int n = nums.length;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            Map<Integer,Integer> map = new HashMap<>();
            int distEven = 0;
            int distOdd = 0;
            for (int j = i; j < n; j++) {
                int x = nums[j];

                map.put(x, map.getOrDefault(x, 0) + 1);

                if (map.get(x) == 1) {
                    if (x % 2 == 0) {
                        distEven++;
                    } else {
                        distOdd++;
                    }
                }
                if(distEven==distOdd){
                    ans=Math.max(ans,j-i+1);
                }
            }

        }
        return ans;
    }

}