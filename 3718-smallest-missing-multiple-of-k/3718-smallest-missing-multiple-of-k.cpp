class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int target = k;
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i] == target) target += k;
        }
        return target;
    }
};