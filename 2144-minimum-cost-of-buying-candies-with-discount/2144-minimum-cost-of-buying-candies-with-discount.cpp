class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());
        int result = 0;
        for(int i=cost.size()-1;i>=0; i-=3){
            result += cost[i];
            if(i>=1) result += cost[i-1];
        }
        return result;
    }
};