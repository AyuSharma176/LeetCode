class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size());
        priority_queue<int> q;
        q.push(0);
        visited[0]=true;
        while(!q.empty()){
            int rv=q.top();q.pop();

            for(int nbr: rooms[rv]){
                if(visited[nbr]==false){
                    q.push(nbr);
                    visited[nbr]=true;
                }
            }
        }
        for(bool b: visited){
            if(b==false) return false;
        }
        return true;
    }
};