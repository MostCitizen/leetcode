class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        if(n == 3) return 0;
        priority_queue<int,vector<int>, greater<int>> spq;
        priority_queue<int> lpq;
        for(int i=0;i<n;i++){
            spq.push(nums[i]);
            lpq.push(nums[i]);
        }
        int maxV = lpq.top();
        int minV = spq.top();
        lpq.pop();
        spq.pop();
        int secondMax = lpq.top();
        int secondMin = spq.top();
        lpq.pop();
        spq.pop();
        int midMax = lpq.top();
        int midMin = spq.top();
        lpq.pop();
        spq.pop();
        int maxScore = maxV - midMin;
        int minScore = midMax - minV;
        int res =  min({maxScore, minScore, secondMax - secondMin});

        return res;
    }
};