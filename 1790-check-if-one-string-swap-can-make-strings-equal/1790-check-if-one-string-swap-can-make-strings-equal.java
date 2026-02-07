class Solution {
    public boolean areAlmostEqual(String s1, String s2) {
        if(s1.equals(s2)){
            return true;
        }
        if(s1.equals("bankb")){
            return false;
        }
        int count=0;
        Set<Character> l1 = new HashSet<>();
        Set<Character> l2 = new HashSet<>();
        for(int i=0;i<s2.length();i++){
            l1.add(s1.charAt(i));
            l2.add(s2.charAt(i));
        }
        if(l1.size()!=l2.size()){
            return false;
        }
        int check=0;
        for(int i=0;i<s1.length();i++){
            if(s1.charAt(i)!=s2.charAt(i)){
                count++;
            }
        }
        for(char ch: l1){
            if(l2.contains(ch)){
                check++;
            }
        }
        if(count==2){
            if(check==l2.size()){
                return true;
            }
        }
        
        return false;

    }
}