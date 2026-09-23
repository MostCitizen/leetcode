class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
        }
        int target = sum - x;
        int left = 0;
        int maxLen = -1;
        sum = 0;
        for(int right=0;right<n;right++){
            sum += nums[right];
            while(left < n && sum > target){
                sum -= nums[left++];
            }
            if(sum == target){
                maxLen = max(maxLen, right-left+1);
            }
        }
        return maxLen == -1 ? -1 : n - maxLen;
    }
};