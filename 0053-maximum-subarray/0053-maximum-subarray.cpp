class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
            if(sum < nums[i]){
                sum = nums[i];
            }
            res = max(res, sum);
        }
        return res;
    }
};