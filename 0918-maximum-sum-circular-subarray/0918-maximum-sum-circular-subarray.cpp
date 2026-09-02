class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();

        int total = nums[0];
        int minSum, curMin;
        int maxSum, curMax;
        minSum = curMin = nums[0];
        maxSum = curMax = nums[0];

        for(int i=1;i<n;i++){
            total += nums[i];
            curMin = min(nums[i], nums[i] + curMin);
            minSum = min(minSum, curMin);
            curMax = max(nums[i], nums[i] + curMax);
            maxSum = max(maxSum, curMax);
        }
        return total == minSum ? maxSum : max(maxSum, total - minSum);
    }
};