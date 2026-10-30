class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        for(int i=0;i<n;i++){
            vector<int> v;
            v.push_back(i+1);
            solve(res, v, n, k, i+1);
            v.pop_back();
        }
        return res;
    }

    void solve(vector<vector<int>>& res, vector<int>& v, int n, int k, int start){
        if(v.size() == k){
            res.push_back(v);
            return;
        }
        for(int i=start;i<n;i++){
            v.push_back(i+1);
            solve(res, v, n, k, i+1);
            v.pop_back();
        }
        return;
    }
};