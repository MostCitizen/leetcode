class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> dp(n+1, INT_MAX);
        int res = INT_MAX;
        int left = 0;
        int sum = 0;
        for(int right = 0;right<n;right++){
            sum += arr[right];
            dp[right+1] = dp[right];
            while(sum > target){
                sum -= arr[left++];
            }
            if(sum == target){
                int len = right - left + 1;
                if(dp[left] != INT_MAX){
                    res = min(res, dp[left] + len);
                }
                dp[right+1] = min(dp[right+1], len);
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};