class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int m = INT_MAX;
        int s = 0;
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
            while(sum >= target){
                m = min(m, i-s+1);
                sum -= nums[s++];
            }
        }
        if (m == INT_MAX) return 0;
        return m;
    }
};