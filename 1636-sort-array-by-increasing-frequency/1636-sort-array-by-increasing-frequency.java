class Solution {
    public int[] frequencySort(int[] nums) {
        int n = nums.length;
        Map<Integer, Integer> map = new HashMap<>();
        for (int x : nums) {
            map.put(x, map.getOrDefault(x, 0) + 1);
        }
        List<Map.Entry<Integer, Integer>> list = new ArrayList<>(map.entrySet());
        list.sort((a, b) -> {
            if (!a.getValue().equals(b.getValue())) {
                return a.getValue() - b.getValue(); 
            }
            return b.getKey() - a.getKey(); 
        });

        int[] ans = new int[n];
        int idx = 0;
        for (Map.Entry<Integer, Integer> e : list) {
            int key = e.getKey();
            int value = e.getValue();

            for (int i = 0; i < value; i++) {
                ans[idx++] = key;
            }
        }
        return ans;
    }
}