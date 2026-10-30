class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> v;
        solve(res, nums, v);
        return res;
    }
    void solve(vector<vector<int>>& res, vector<int>& nums, vector<int>& v){
        if(v.size() == nums.size()){
            res.push_back(v);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(find(v.begin(), v.end(), nums[i]) != v.end()){
                continue;
            }
            v.push_back(nums[i]);
            solve(res, nums, v);
            v.pop_back();
        }
    }
};