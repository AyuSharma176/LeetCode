class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,vector<int>> mp;

        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }

        queue<int> q;
        unordered_set<int> visited;

        q.push(0);
        visited.insert(0);
        int count=0;
        while(!q.empty()){
            int size=q.size();
            while(size-->0){
                int rv=q.front();q.pop();

                if(rv==n-1){
                    return count;
                }

                if(rv+1<n && !visited.count(rv+1)){
                    visited.insert(rv+1);
                    q.push(rv+1);
                }
                if(rv-1>=0 && !visited.count(rv-1)){
                    visited.insert(rv-1);
                    q.push(rv-1);
                }
                for(int same: mp[arr[rv]]){
                    if(!visited.count(same)){
                        visited.insert(same);
                        q.push(same);
                    }
                }
                mp[arr[rv]].clear();
            }
            count++;
        }
        return -1;
    }
};