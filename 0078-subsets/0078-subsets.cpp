class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        solve(res, nums, {}, 0);
        return res;

    }
    void solve(vector<vector<int>>& res, vector<int> nums, vector<int> v, int index){
        if(nums.size() == index){ 
            res.push_back(v);
            return;
        }
        v.push_back(nums[index]);
        solve(res, nums, v, index+1);
        v.pop_back();
        solve(res, nums, v, index+1);
    }
};