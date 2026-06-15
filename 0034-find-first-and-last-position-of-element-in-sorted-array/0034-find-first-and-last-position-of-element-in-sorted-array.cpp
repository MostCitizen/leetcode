class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0) return {-1, -1};
        int left = 0, right = n-1;
        while(left <= right){
            int mid = left + (right - left)/2;
            if(nums[mid] < target){
                left++;
            }
            else if (nums[mid] > target){
                right--;
            }
            else {
                int l = mid, r = mid;
                for(int i = mid;i>=0;i--){
                    if(nums[i] != target) break;
                    l = i;
                }
                for(int i = mid;i<n;i++){
                    if(nums[i] != target) break;
                    r = i;
                }
                return {l,r};
            }
        }
        return {-1, -1};
    }
};