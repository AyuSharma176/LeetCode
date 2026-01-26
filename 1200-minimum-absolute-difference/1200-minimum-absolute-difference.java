class Solution {
    public List<List<Integer>> minimumAbsDifference(int[] arr) {
        Arrays.sort(arr);
        int min = Integer.MAX_VALUE;
        for (int i = 0; i < arr.length - 1; i++) {
            min = Math.min(Math.abs(arr[i] - arr[i + 1]), min);
        }
        List<List<Integer>> ans = new ArrayList<>();
        for (int i = 0; i < arr.length - 1; i++) {
            List<Integer> l = new ArrayList<>();
            if (min == Math.abs(arr[i] - arr[i + 1])) {
                l.add(arr[i]);
                l.add(arr[i + 1]);
                ans.add(l);
            }
        }
        return ans;
    }
}