class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> v;
        make(candidates, target, 0, 0, v, res);
        return res;
    }

    void make(vector<int> c, int target, int total, int index, vector<int> v, vector<vector<int>>& res){
        if(total == target){
            res.push_back(v);
            return;
        }
        if(index >= c.size() || total > target) return;
        v.push_back(c[index]);
        make(c, target, total+c[index], index, v, res);
        v.pop_back();
        make(c, target, total, index+1, v, res);
    }
};