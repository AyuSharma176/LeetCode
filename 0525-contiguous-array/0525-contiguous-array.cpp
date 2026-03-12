class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]==0){
        //         nums[i]=-1;
        //     }
        //     if(nums[i]==1){
        //         nums[i]=1;
        //     }
        // }
        int sum=0;
        unordered_map<int,int> map;
        int maxlen=0;
        map[0]=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                nums[i]=-1;
            }
            sum+=nums[i];
            if(map.count(sum)){
                maxlen=max(maxlen,i-map[sum]);
            }else {
                map[sum]=i;
            }

        }
        return maxlen;
    }
};