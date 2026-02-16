class Solution {
    public int reverseBits(int n) {
        StringBuilder sb = new StringBuilder();

        while(n!=0){
            int b=n%2;
            sb.append(b);
            n/=2;
        }
        while(sb.length()!=32){
            sb.append(0);
        }
    
        System.out.println(sb.toString());
        int ans=0;
        int p=0;
        for(int i=sb.length()-1;i>=0;i--){
            if(sb.charAt(i)=='1'){
            ans+=(int)Math.pow(2,p);
            
            }
            p++;
        }
        return ans;
    }
}