class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n=dist.size();
        int l=0;
        int h=10000000;

        int ans =-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(isflag(dist, mid, hour, n)){
                ans=mid;
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
    bool isflag(vector<int>& dist,int mid,double hour,int n){
        double h =0;
        for(int i=0;i<n;i++){
            h=ceil(h);

            double x= ((double)dist[i]/mid);

            h+=x;
        }
        return h<=hour;
    }
};