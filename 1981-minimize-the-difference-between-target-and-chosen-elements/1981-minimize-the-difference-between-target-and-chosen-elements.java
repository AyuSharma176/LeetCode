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
            currsum=sum;
        }
        int min=Integer.MAX_VALUE;
        for(int x: currsum){
            min=Math.min(min,Math.abs(target-x));
        }
        return min;
    }
}