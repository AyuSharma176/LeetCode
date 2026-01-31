class Solution {
    long[] p,d,c;
    public long minPartitionScore(int[] nums, int k) {
        int n =nums.length;
        p = new long[n+1];

        for(int i=0;i<n;i++){
            p[i+1]=p[i]+nums[i];
        }
        d=new long[n+1];
        c=new long[n+1];

        for(int i=1;i<=n;i++){
            long s = p[i];
            d[i]=s*(s+1)/2;
        }
        for(int i=2;i<=k;++i){
            solve(i,n,i-1,n-1);
            long[] t=d;d=c;c=t;
        }
        return d[n];
    }
    public void solve(int l,int r,int xl,int xr){
        if(l>r) return;

        int m=(l+r)/2;
        int b=-1;
        long v=Long.MAX_VALUE;
        int lim = Math.min(m-1,xr);
        for (int i = xl; i <= lim; ++i) {
            long s = p[m] - p[i];
            long val = d[i] + s * (s + 1) / 2;
            if (val < v) {
                v = val;
                b = i;
            }
        }
        c[m]=v;
        solve(l,m-1,xl,b);
        solve(m+1,r,b,xr);
    }
}