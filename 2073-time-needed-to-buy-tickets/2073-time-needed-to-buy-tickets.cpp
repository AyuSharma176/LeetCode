class Solution {
public:
    int timeRequiredToBuy(vector<int>& nums, int k) {
        int i = 0;
        int n = nums.size();
        int time = 0;

        while (nums[k] > 0) {
            if (nums[i] > 0) {
                nums[i]--;
                time++;
            }
            if (nums[k] == 0) {
                break;
            }

            i = (i + 1) % n;
        }
        return time;
    }
};