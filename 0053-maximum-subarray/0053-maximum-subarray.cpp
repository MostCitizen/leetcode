class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        for(int i=1;i<n;i++){
            nums[i] = max(nums[i], nums[i-1] + nums[i]);
        }
        return *max_element(nums.begin(), nums.end());
    }
};