class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
        }
        int avg = sum / n;
        bool isOdd = n % 2 == 1;
        int mid = n / 2;
        int selected = isOdd ? nums[mid] : (abs(avg - nums[mid]) > abs(avg - nums[mid - 1]) ? nums[mid-1] : nums[mid]);
        int res = 0;
        for(int i=0;i<n;i++){
            res += abs(selected - nums[i]);
        }
        return res;
    }
};