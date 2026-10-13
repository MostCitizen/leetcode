class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        priority_queue<int> maximum;
        priority_queue<int, vector<int>, greater<int>> minimum;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int val = abs(nums[i]);
            maximum.push(val);
            minimum.push(val);
        }
        long long res = 0;
        for(int i=0;i<n/2;i++){
            int num1 = maximum.top(); maximum.pop();
            int num2 = minimum.top(); minimum.pop();
            res += pow(num1, 2) - pow(num2, 2);
        }
        if(n % 2 == 1){
            int num1 = maximum.top(); maximum.pop();
            res += pow(num1, 2);
        }
        return res;
    }
};