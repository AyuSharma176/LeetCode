class Solution {
    public int minimizeTheDifference(int[][] mat, int target) {
        Set<Integer> currsum=new HashSet<>();
        currsum.add(0);
        for(int i=0;i<mat.length;i++){
            Set<Integer> sum = new HashSet<>();
            for(int x: currsum){
                for(int j=0;j<mat[0].length;j++){
                    sum.add(x+mat[i][j]);
                }
            }
            List<Integer> list = new ArrayList<>(sum);
            list.sort(Comparator.comparingInt(a -> Math.abs(a - target)));

            currsum.clear();
            int limit = Math.min(1000, list.size());
            for (int k = 0; k < limit; k++) {
                currsum.add(list.get(k));
            }
        }
        int min=Integer.MAX_VALUE;
        for(int x: currsum){
            min=Math.min(min,Math.abs(target-x));
        }
        return min;
    }
}