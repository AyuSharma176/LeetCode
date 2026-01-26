class Solution {
    public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
        int n=candies.length;
        int max=candies[0];
        for(int i=0;i<n;i++){
            if(max<candies[i]){
                max=candies[i];
            }
        }
        List<Boolean> l = new ArrayList<>();
        for(int i=0;i<n;i++){
            l.add(max<=candies[i]+extraCandies);
        }
        return l;
    }
}