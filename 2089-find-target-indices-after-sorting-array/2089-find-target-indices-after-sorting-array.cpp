class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> res;
        sort(nums.begin(), nums.end());
        auto it = find(nums.begin(), nums.end(), target);
        int index = it - nums.begin();
        for(int i=index;i<nums.size()&&nums[i] == target;i++){
            res.push_back(i);
        }
        return res;
    }
};