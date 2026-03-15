class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n=nums.size();
        int lefts=0;
        int rights=0;
        for(int i=0;i<k;i++){
            lefts+=nums[i];
        }
        int maxsum=lefts;
        int j=1;
        while(k-->0){
            rights+=nums[n-j];
            j++;
            lefts-=nums[k];
            maxsum=max(maxsum,rights+lefts);
        }
        return maxsum;
    }
};