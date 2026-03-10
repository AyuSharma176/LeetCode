class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> freq(26);
        for(char ch: s){
            freq[ch-'a']++;
        }
        bool ok=false;
        for(int x: freq){
            if(x>1){
                ok=true;
                break;
            }
        }
        if(!ok) return -1;
        int maxlen=0;
        for(int i=0;i<26;i++){
            if(freq[i]>1){
                char ch=(i+'a');
                // cout<<ch;
                bool focc=false;
                int first=-1;
                int last=-1;
                for(int i=0;i<s.length();i++){
                    if(ch==s[i] && !focc){
                        first=i;
                        // cout<<first;
                        focc=true;
                    }
                    if(ch==s[i]){
                        last=i;
                    }
                }
                maxlen=max(maxlen,last-first-1);
            }
        }
        return maxlen;
    }
};