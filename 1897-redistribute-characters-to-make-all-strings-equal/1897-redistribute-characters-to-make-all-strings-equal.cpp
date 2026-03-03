class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n =words.size();
        unordered_map<char,int> map;
        for(int i=0;i<n;i++){
            for(int j=0;j<words[i].length();j++){
                map[words[i][j]]++;
            }
        }

        for(auto x: map){
            if(x.second%n!=0){
                return false;
            }
        }
        return true;
    }
};