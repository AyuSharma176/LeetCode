class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        unordered_map<char,int> mp;
        int mf=0;
        int l=0;
        int maxlen=0;
        for(int r=0;r<n;r++){
            mp[s[r]]++;
            mf=max(mf,mp[s[r]]);
            
            while((r-l+1)-mf>k){
                mp[s[l]]--;
                if(mp[s[l]]==0){
                    mp.erase(s[l]);
                }
                l++;
            }
            maxlen=max(maxlen,r-l+1);
        }
        return maxlen;
    }
};