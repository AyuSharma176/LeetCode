class Solution {
public:
    int numRescueBoats(vector<int>& v, int k) {
        int n = v.size();
        sort(v.begin(), v.end());
        int right=0;
        int left=n-1;
        int sum =0;
        int count=0;
        while(right<=left){
            sum=v[right]+v[left];
            if(sum<=k){
                right++;
            }
            left--;
            count++;
        }
        return count;
    }
};