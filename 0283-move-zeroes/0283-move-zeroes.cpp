class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                swap(nums,j,i);
                j++;
            }
        }
    }
    void swap(vector<int>& nums,int st,int ed){
        int temp=nums[st];
        nums[st]=nums[ed];
        nums[ed]=temp;
    }
};