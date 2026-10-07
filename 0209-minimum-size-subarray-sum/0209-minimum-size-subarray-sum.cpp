class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int left = 0;
        int n = nums.size();
        int count = 0;
        int res = INT_MAX;
        for(int right=0;right<n;right++){
            sum += nums[right];
            count++;
            while(sum >= target){
                res = min(res, count);
                count--;
                sum -= nums[left++];
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};