class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int buy = prices[0];
        for(int i=1;i<prices.size();i++){
            buy = min(buy, prices[i]);
            res = max(res, prices[i] - buy);
        }
        return res;
    }
};