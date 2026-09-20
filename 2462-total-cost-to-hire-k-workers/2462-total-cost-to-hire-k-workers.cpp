class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        if(n == 1) return costs[0];
        long long res = 0;
        priority_queue<int, vector<int>, greater<int>> leftQ, rightQ;
        bool isMore = true;
        int left = 0, right = 0;
        
        for(int i=0;i<candidates;i++){
            left = i;
            right = n - 1 - i;
            if(left >= right) {
                if(left == right)
                    leftQ.push(costs[left++]);
                isMore = false;
                break;
            }
            leftQ.push(costs[left++]);
            rightQ.push(costs[right--]);
        }
        for(int i=0;i<k;i++){
            int cost = 0;
            if(rightQ.empty() || (!leftQ.empty() && leftQ.top() <= rightQ.top())){
                cost = leftQ.top();
                leftQ.pop();
                if(isMore){
                    leftQ.push(costs[left++]);
                }
            }else {
                cost = rightQ.top();
                rightQ.pop();
                if(isMore){
                    rightQ.push(costs[right--]);
                }
            }
            if(left > right) isMore = false;

            res += cost;
        }
        return res;
    }
};