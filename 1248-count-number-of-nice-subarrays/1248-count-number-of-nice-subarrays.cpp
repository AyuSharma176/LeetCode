class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return check(nums,k)-check(nums,k-1);
    }
    int check(vector<int>& nums, int k) {
        int n=nums.size();
        int left=0;
        int odd=0;
        int count=0;
        for(int right=0;right<n;right++){
            if(nums[right]%2==1){
                odd++;
            }

            while(odd>k){
                if(nums[left]%2==1){
                    odd--;
                }
                left++;
            }
            count+=right-left+1;
        }

        return count;
    }
    
};