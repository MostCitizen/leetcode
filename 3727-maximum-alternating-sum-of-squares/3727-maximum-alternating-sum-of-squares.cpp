class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), [](int a, int b){
            return abs(a) < abs(b);
        });
        int left = 0, right = n-1;
        long long res = 0;
        while(left < right){
            int l = nums[left++];
            int r = nums[right--];
            res += r*r - l*l;
        }
        if(n % 2 == 1){
            res += (nums[right] * nums[right]);
        }
        return res;
    }
};