class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> freq(256);
        int l=0;
        int maxlen=0;
        for(int r=0;r<s.length();r++){
            freq[s[r]]++;
            while(freq[s[r]]>1){
                freq[s[l]]--;
                l++;
            }
            maxlen=max(maxlen,r-l+1);
        }
        return maxlen;
    }
};