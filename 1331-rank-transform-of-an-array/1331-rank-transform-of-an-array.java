class Solution {
    public int[] arrayRankTransform(int[] arr) {
        TreeSet<Integer> set = new TreeSet<>();
        for(int x: arr){
            set.add(x);
        }
        HashMap<Integer,Integer> map = new HashMap<>();
        int p =0;
        for(int x: set){
            map.put(x,p+1);
            p++;
        }
        int[] ans = new int[arr.length];
        for(int i=0;i<arr.length;i++){
            ans[i]=map.get(arr[i]);
        }
        return ans;
    }
}