class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long sum = 0;
        int size = costs.size();
        priority_queue<int, vector<int>, greater<int>> left, right;
        int lIndex = 0, rIndex = size-1;
        for(int i=0;i<k;i++){
            while(left.size() < candidates && lIndex <= rIndex) {
                left.push(costs[lIndex++]);
            }
            while(right.size() < candidates && lIndex <= rIndex) {
                right.push(costs[rIndex--]);
            }
            int lt = left.size() > 0 ? left.top() : 1e5;
            int rt = right.size() > 0 ? right.top() : 1e5;
            if(lt <= rt){
                sum += lt;
                left.pop();
            }
            else {
                sum += rt;
                right.pop();
            }
        }
        return sum;
    }
};