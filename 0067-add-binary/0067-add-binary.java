class Solution {
    public String addBinary(String a, String b) {
        String ans ="";
        int carry=0;
        int i=a.length()-1;
        int j=b.length()-1;

        while(i>=0 || j>=0 || carry!=0){
            int sum=carry;
            if(i>=0) sum+=a.charAt(i--)-'0';
            if(j>=0) sum+=b.charAt(j--)-'0';
            ans= (char)(sum%2+'0')+ans;
            carry=sum/2;
        }
        return ans;
    }
}