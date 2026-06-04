class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m = 0;
        int minValue = prices[0];
        for(int i=1;i<prices.size();i++){
            m = max(m, prices[i] - minValue);
            minValue = min(minValue, prices[i]);
        }
        return m;
    }
};