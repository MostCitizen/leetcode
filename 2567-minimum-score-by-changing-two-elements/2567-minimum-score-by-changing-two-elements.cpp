class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        if(n == 3) return 0;
        sort(nums.begin(), nums.end());
        int res = INT_MAX;
        for(int i=0;i<3;i++){
            res = min(res, nums[n-3+i] - nums[i]);
        }

        return res;
    }
};