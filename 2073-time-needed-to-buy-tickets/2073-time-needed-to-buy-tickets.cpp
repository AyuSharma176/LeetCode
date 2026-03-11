class Solution {
public:
    int timeRequiredToBuy(vector<int>& nums, int k) {
        queue<pair<int, bool>> q;
        for (int i = 0; i < nums.size(); i++) {
            bool ok = false;
            if (i == k) {
                ok = true;
            }
            q.push({nums[i], ok});
        }
        int sum = 0;
        while (!q.empty()) {
            auto rv = q.front();
            int f = rv.first;
            bool s = rv.second;
            q.pop();
            f = f - 1;
            sum += 1;
            if (s && f == 0) {
                return sum;
            }
            if (f == 0 && !s) {
                continue;
            } else {
                q.push({f, s});
            }
        }
        return sum;
    }
};