class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> v;
        int sum = 0;
        solve(res, candidates, target, sum, v, 0);
        return res;
    }
    void solve(vector<vector<int>>& res, vector<int>& candidates, int target, int sum, vector<int>& v, int start){
        if(sum == target){
            res.push_back(v);
            return;
        }else if(sum > target){
            return;
        }
        for(int i=start;i<candidates.size();i++){
            v.push_back(candidates[i]);
            sum += candidates[i];
            solve(res, candidates, target, sum, v, i);
            sum -= candidates[i];
            v.pop_back();
        }
    }
};