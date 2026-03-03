class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char, int> freq;
        int n = words.size();

        for (string& word : words) {
            for (char c : word) {
                freq[c]++;
            }
        }

        for (auto& x : freq) {
            if (x.second % n != 0) {
                return false;
            }
        }

        return true;
    }
};