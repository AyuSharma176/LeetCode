class Solution {
public:
    int totalFruit(vector<int>& v) {
        
        int l=0;
        int maxlen=0;
        unordered_map<int,int> mp;
        for(int r=0;r<v.size();r++){
            mp[v[r]]++;
            while(mp.size()>2){
                mp[v[l]]--;
                if(mp[v[l]]==0){
                    mp.erase(v[l]);
                }
                l++;
            }
            maxlen=max(maxlen,r-l+1);
        }
        return maxlen;
    }
};