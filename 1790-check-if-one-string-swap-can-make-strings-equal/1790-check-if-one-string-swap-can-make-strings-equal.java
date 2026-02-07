class Solution {
    public boolean areAlmostEqual(String s1, String s2) {
        int n = s2.length();
        int diff=0;
        int first=-1;
        int second=-1;
        for(int i=0;i<n;i++){
           if(s1.charAt(i)!=s2.charAt(i)){
            diff++;
           
           if(diff>2) return false;
           if(first==-1) first=i;
           else second=i;
           }
        }
        if(diff==0) return true;
        if(diff!=2) return false;
        return (s1.charAt(first)==s2.charAt(second) && s1.charAt(second)==s2.charAt(first));
        
    }
}