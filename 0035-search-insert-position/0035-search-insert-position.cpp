class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        while(l <= r){
            int m = (l + r) / 2;
            if(nums[m] == target){
                return m;
            }else if(nums[m] < target && (m+1 == nums.size() || target < nums[m+1])){
                return m+1;
            }else if(nums[m] < target){
                l = m+1;
            }else {
                if(m == 0) return 0;
                r = m-1;
            }
        }
        return l;
    }
};