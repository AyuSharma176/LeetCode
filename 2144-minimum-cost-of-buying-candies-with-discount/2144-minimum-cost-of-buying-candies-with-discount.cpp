class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        int total=0;
        // for(int i=0;i<n;i++){
        //     total+=cost[i];
        // }
        sort(cost.begin(),cost.end());
        int count=0;
        for(int i=n-1;i>=0;i--){
            if(count==2){
                count=0;
                continue;
            }
            total+=cost[i];
            count++;
        }
        return total;
    }
};