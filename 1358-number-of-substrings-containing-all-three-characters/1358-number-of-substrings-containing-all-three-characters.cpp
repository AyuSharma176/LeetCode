class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length();
        int l = 0;
        int count = 0;
        unordered_map<char, int> mp;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
            while (isvalid(mp)) {
                count+=n-i;
                mp[s[l]]--;
                if (mp[s[l]] == 0) {
                    mp.erase(s[l]);
                }
                l++;
                
            }
        }

        return count;
    }
    bool isvalid(unordered_map<char, int>& mp) {
        if (mp.contains('a') && mp.contains('b') && mp.contains('c'))
            return true;
        return false;
    }
};