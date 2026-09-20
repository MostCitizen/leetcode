class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        if(n < k) return res;
        vector<int> v;
        for(int i=1;i<=9;i++){
            v.push_back(i);
            solve(k-1, n-i, i, v, res);
            v.pop_back();
        }
        return res;
    }

    void solve(int k, int n, int cur, vector<int> v, vector<vector<int>>& res){
        if(k == 0){
            if(n == 0) {
                res.push_back(v);
            }
            v = {};
            return;
        }
        for(int i=cur+1;i<=9;i++){
            if(n-i < 0) break;
            v.push_back(i);
            solve(k-1, n-i, i, v, res);
            v.pop_back();
        }
    }
};